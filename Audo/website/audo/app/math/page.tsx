"use client"
import * as React from "react";
import { useState } from "react"; 
import { useRouter } from "next/navigation";
import { Button } from "@/components/ui/button";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";

export default function Home() {
  const [progress, setProgress] = useState(0);
  const [currentQuestionIndex, setCurrentQuestionIndex] = useState(0);
  const [selectedAnswerIndex, setSelectedAnswerIndex] = useState(null);
    const router = useRouter()

    const questions = [
      "What is 5+35+3?",
      "Solve for x in the equation 2x + 4 = 10.",
      "What is the square root of 49?",
      "What is 3 × 4?",
      "Solve for y in the equation 2y − 5 = 7",
      "What is 1/2 + 1/3?",
      "What is 9−5?",
      "Solve for x in the equation 3x − 2 = 10.",
      "What is 7 × 6?",
      "What is 3/4 x 8?",
      "What is 20 ÷ 5?",
    ];
  
    const rightAnswers = [
      "43",
      "3",
      "7",
      "12",
      "12",
      "2/3",
      "4",
      "4",
      "42",
      "6",
      "4",
    ];
  
    const wrongAnswers = [
      ["7", "8", "6"],
      ["15", "9", "5"],
      ["1", "9", "8"],
      ["3", "18", "8"],
      ["7", "2", "9"],
      ["1/2", "4", "3/5"],
      ["14", "22", "12"],
      ["2", "8", "5"],
      ["111", "29", "35"],
      ["5", "12", "2"],
      ["5", "10", "8"],
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
    setSelectedAnswerIndex(index);
  };

  const handleSubmit = () => {
    router.push(`/app/grade.tsx`);
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
          <Button className="bg-gradient-to-r from-indigo-300 via-slate-800 to-indigo-300 text-white py-3 px-6 rounded-md text-center transition duration-300 hover:bg-blue-600 text-xl" onClick={isLastQuestion ?() =>  router.push('/grade') : handleIncrementButtonClick}>
            {isLastQuestion ? 'Submit' : 'Next'}
          </Button>
        </div>
      </CardContent>
    </Card>
  )
}
