"use client"
import * as React from "react";
import { useState } from "react"; 
import { useRouter } from "next/navigation";
import { Button } from "@/components/ui/button";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import { updateTotalStorageTests } from "@/utils/service";

export default function Home() {
  const [progress, setProgress] = useState(0);
  const [currentQuestionIndex, setCurrentQuestionIndex] = useState(0);
  const [selectedAnswerIndex, setSelectedAnswerIndex] = useState(null);
    const router = useRouter()

    const questions = [
      "What were the main causes of World War I?",
      "How did the Treaty of Versailles contribute to the outbreak of World War II?",
      "Describe the significance of the Industrial Revolution in shaping modern society.",
      "What were the key events and consequences of the French Revolution?",
      "Explain the impact of imperialism on the colonized regions and the colonial powers.",
      "What were the major factors leading to the rise of fascism in Europe during the 20th century?",
      "Discuss the significance of the Civil Rights Movement in the United States during the 20th century.",
      "How did the Cold War influence global politics and society?",
      "Describe the origins and consequences of the Great Depression in the 1930s.",
      "What were the main causes and effects of the Russian Revolution of 1917?",
      "Explain the role of technology in shaping warfare during World War I and World War II.",
    ];
  
    const rightAnswers = [
      "It was caused by a complex web of alliances, militarism, imperialism, and nationalism.",
      "It strengthened Germany's economy and military power.",
      "It led to urbanization, technological advancements, and the rise of capitalism.",
      "It had no long-term consequences.",
      "It promoted democracy and human rights in the colonized regions.",
      "Economic instability, nationalism, and dissatisfaction with the Treaty of Versailles.",
      "It led to legal reforms, desegregation, and increased awareness of racial injustice.",
      "It caused global division, nuclear proliferation, and proxy wars.",
      "It resulted in economic prosperity and growth.",
      "It had no lasting effects on Russian society.",
      "It introduced tanks, airplanes, and chemical weapons, changing warfare."
    ];
  
    const wrongAnswers = [
      [
        "It was caused by tensions between France and Germany.", 
        "It was caused by the sinking of the Titanic."
      ],
      [
        "Heavy reparations on Germany caused economic hardship and resentment.", 
        "It brought lasting peace and stability to Europe."
      ],
      [
        "It resulted in the decline of factories and the resurgence of agriculture.", 
        "It had no significant impact on society."
      ],
      [
        "It led to the monarchy's overthrow, the Reign of Terror, and Napoleon's rise.", 
        "It established a constitutional monarchy and peaceful reforms."
      ],
      [
        "It led to exploitation, cultural assimilation, and economic dependency in colonies.", 
        "It had no effect on the colonial powers."
      ],
      [
        "The promotion of democracy and social equality.", 
        "International cooperation and peace treaties."
      ],
      [
        "It had no impact on race relations in the United States.", 
        "It resulted in increased segregation and discrimination."
      ],
      [
        "It fostered peaceful cooperation between the US and Soviet Union.", 
        "It had no impact outside of Europe."
      ],
      [
        "It started with the 1929 crash, causing widespread hardship.", 
        "It was caused by excessive government intervention in the economy."
      ],
      [
        "It arose from discontent, overthrowing the Tsarist regime for communism.", 
        "It was instigated by foreign powers seeking to destabilize Russia."
      ],
      [
        "Technology had no significant impact on warfare during these periods.", 
        "Warfare remained largely unchanged, relying on traditional tactics and weapons."
      ]
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
  
  const onNextClick = () => {

  }

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
          <Button onClickCapture={isLastQuestion ? updateTotalStorageTests : onNextClick } className="bg-gradient-to-r from-indigo-300 via-slate-800 to-indigo-300 text-white py-3 px-6 rounded-md text-center transition duration-300 hover:bg-blue-600 text-xl" onClick={isLastQuestion ?() =>  router.push('/grade') : handleIncrementButtonClick}>
            {isLastQuestion ? 'Submit' : 'Next'}
          </Button>
        </div>
      </CardContent>
    </Card>
  )
}
