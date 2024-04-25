"use client"
import * as React from "react";
import { useState } from "react"; 
import { useRouter } from "next/navigation";
import { Button } from "@/components/ui/button";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import Cookies from "js-cookie";

export default function Home() {
  const [progress, setProgress] = useState(0);
  const [currentQuestionIndex, setCurrentQuestionIndex] = useState(0);
  const [selectedAnswerIndex, setSelectedAnswerIndex] = useState(null);
  const [answers, setAnswers] = useState([]);
  let router = useRouter();

  const questions = [
    "What is the unit of measurement for force?",
    "What is Newton's first law of motion also known as?",
    "What is the SI unit of power?",
    "What is the acceleration due to gravity on Earth?",
    "What is the law of conservation of energy?",
    "What is the formula for calculating kinetic energy?",
    "What is the principle behind the operation of a lever?",
    "What is the relationship between force, mass, and acceleration according to Newton's second law?",
    "What is the unit of measurement for electrical resistance?",
    "What is the formula for calculating work?",
    "What is the phenomenon responsible for the bending of light?",
  ];

  const rightAnswers = [
    "Newton",
    "Law of inertia",
    "Watt",
    "9.8 m/sÂ²",
    "Energy cannot be created or destroyed, only transformed from one form to another.",
    "0.5 * mass * velocity^2",
    "A rigid bar that pivots around a fixed point.",
    "Force equals mass times acceleration (F=ma).",
    "Ohm",
    "Force times distance (W=Fd)",
    "Refraction",
  ];

  const wrongAnswers = [
    ["Joule", "Pascal"],
    ["Law of action-reaction", "Law of gravitation"],
    ["Joule", "Volt"],
    ["6.67 x 10^-11 Nm^2/kg^2", "3 x 10^8 m/s"],
    ["Energy increases with temperature.", "Energy decreases with altitude."],
    ["mass * acceleration", "force * distance"],
    ["The larger the effort force, the smaller the load force needed.", "The longer the lever arm, the greater the mechanical advantage."],
    ["Force equals distance divided by time (F=d/t).", "Force equals momentum times velocity (F=mv)."],
    ["Volt", "Ampere"],
    ["Mass times velocity squared (W=1/2mv^2)", "Force times acceleration (W=ma)"],
    ["Reflection", "Diffraction"],
  ];

  const handleDecrementButtonClick = () => {
    if (progress > 0) {
      setProgress(progress - 10);
    }
    setCurrentQuestionIndex((prevIndex) => (prevIndex - 1 + questions.length) % questions.length);
    setSelectedAnswerIndex(null);
  };

  const handleIncrementButtonClick = () => {
    if (progress < 100) {
      setProgress(progress + 10);
    }
    setCurrentQuestionIndex((prevIndex) => (prevIndex + 1) % questions.length);
    setSelectedAnswerIndex(null);
  };

const handleAnswerChange = (index) => {
  if (selectedAnswerIndex === index) {
    setAnswers(answers.filter((_, i) => i !== currentQuestionIndex));
  } else {
    let answer = index === null ? rightAnswers[currentQuestionIndex] : wrongAnswers[currentQuestionIndex][index];
    handleAnswerSubmit(questions[currentQuestionIndex], answer);
  }
  setSelectedAnswerIndex(index);
};
const handleAnswerSubmit = (question, answer) => {
  setAnswers([...answers, { question, answer }]);
};

const handleSubmit = async (answers : any[]) => {
  let token = Cookies.get("token");
  let submit = Number(Cookies.get("counter"));
  submit+= 1;
  Cookies.set("counter", submit);
  if (!token) 
    router.push("/login");
else {
  const formattedAnswers = answers.map((answer, index) => ({
    question: questions[index],
    answer: answer,
  }));

  let res = await fetch("http://localhost:45098/api/submit/test", {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      "Authorization": `Bearer ${token}`,
    },
    body: JSON.stringify({
      subject: "physics",
      answers: formattedAnswers,
    }),
  });

  console.log(JSON.stringify({
      subject: "physics",
      answers: formattedAnswers,
    }))

  if (res.ok){
    router.push("/");
  }
}
};
  const isLastQuestion = currentQuestionIndex === questions.length - 1;
  return (
        <Card className="w-[80vw] h-[80vh] ml-[10vw] mt-[10vh]">
                <div className="h-2 bg-gray-200 rounded-md mb-4">
                  <div className="h-full bg-blue-800 rounded-md" style={{ width: `${progress}%` }}></div>
                </div>

                <CardHeader>
                  <CardTitle className="text-4xl font-black text-blue-800 dark:text-white text-center mt-[5vw] pl-[20vw] pr-[20vw]">{questions[currentQuestionIndex]}</CardTitle>
                </CardHeader>

                <CardContent className="flex justify-center flex-col items-center">
                  <div className="flex flex-col items-start space-y-2">
                  <>
            <label key="right" className="flex items-center space-x-2 mt-[6vh]">
              <input
                type="radio"
                name="answer"
                checked={selectedAnswerIndex === null}
                onChange={() => handleAnswerChange(null)}
                className="appearance-none h-5 w-5 border border-gray-300 rounded-full checked:bg-blue-800 checked:border-transparent focus:outline-none"
              />
              <span className="text-3xl font-semibold text-slate-500 dark:text-white text-center pl-5 ">{rightAnswers[currentQuestionIndex]}</span>
            </label>
            {wrongAnswers[currentQuestionIndex].map((answer, index) => (
              <label key={index} className="flex items-center space-x-2 ">
                <input
                  type="radio"
                  name="answer"
                  checked={selectedAnswerIndex === index}
                  onChange={() => handleAnswerChange(index)}
                  className="appearance-none h-5 w-5 border border-gray-300 rounded-full checked:bg-blue-800 checked:border-transparent focus:outline-none"
                />
                <span className="text-3xl font-semibold text-slate-500 dark:text-white text-center pl-5">{answer}</span>
              </label>
            ))}
          </>
        </div>
        <div className="flex justify-center space-x-96 mt-[7vw]">
          <Button className="bg-gradient-to-r from-indigo-300 via-slate-800 to-indigo-300 text-white py-3 px-6 rounded-md text-center transition duration-300 hover:bg-blue-600 text-xl" onClick={handleDecrementButtonClick}>Prev</Button>
          <Button className="bg-gradient-to-r from-indigo-300 via-slate-800 to-indigo-300 text-white py-3 px-6 rounded-md text-center transition duration-300 hover:bg-blue-600 text-xl" onClick={isLastQuestion ?() =>  handleSubmit(answers) : handleIncrementButtonClick}>
            {isLastQuestion ? 'Submit' : 'Next'}
          </Button>
        </div>
      </CardContent>
    </Card>
  )
}
