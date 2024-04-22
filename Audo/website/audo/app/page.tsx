"use client"
import * as React from "react"
import { useState } from "react"; 
import { useRouter } from "next/router";

import { Button } from "@/components/ui/button"
import {
  Card,
  CardContent,
  CardHeader,
  CardTitle,
} from "@/components/ui/card"

export default function Home() {
  const [progress, setProgress] = useState(0);
  const [currentQuestionIndex, setCurrentQuestionIndex] = useState(0);
  const [selectedAnswerIndex, setSelectedAnswerIndex] = useState(null);
  const [grade, setGrade] = useState('F');


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

  const answers = [
    ["It was caused by tensions between France and Germany.", 
    "It was caused by the sinking of the Titanic.", 
    "It was caused by a complex web of alliances, militarism, imperialism, and nationalism."],
    ["Heavy reparations on Germany caused economic hardship and resentment.", 
    "It brought lasting peace and stability to Europe.", 
    "It strengthened Germany's economy and military power."],
    ["It led to urbanization, technological advancements, and the rise of capitalism.", 
    "It resulted in the decline of factories and the resurgence of agriculture.", 
    "It had no significant impact on society."],
    ["It led to the monarchy's overthrow, the Reign of Terror, and Napoleon's rise.", 
    "It established a constitutional monarchy and peaceful reforms.", 
    "It had no long-term consequences."],
    ["It led to exploitation, cultural assimilation, and economic dependency in colonies.", 
    "It promoted democracy and human rights in the colonized regions.", 
    "It had no effect on the colonial powers."],
    ["Economic instability, nationalism, and dissatisfaction with the Treaty of Versailles.", 
    "The promotion of democracy and social equality.", 
    "International cooperation and peace treaties."],
    ["It led to legal reforms, desegregation, and increased awareness of racial injustice.", 
    "It had no impact on race relations in the United States.", 
    " It resulted in increased segregation and discrimination."],
    ["It caused global division, nuclear proliferation, and proxy wars.", 
    "It fostered peaceful cooperation between the US and Soviet Union.", 
    "It had no impact outside of Europe."],
    ["It started with the 1929 crash, causing widespread hardship.", 
    "It was caused by excessive government intervention in the economy.", 
    "It resulted in economic prosperity and growth."],
    ["It arose from discontent, overthrowing the Tsarist regime for communism.",
    "It was instigated by foreign powers seeking to destabilize Russia.", 
    "It had no lasting effects on Russian society."],
    ["It introduced tanks, airplanes, and chemical weapons, changing warfare.", 
    "Technology had no significant impact on warfare during these periods.", 
    "Warfare remained largely unchanged, relying on traditional tactics and weapons."],
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

  const handleAnswerChange = (index, isTrueAnswer) => {
    setSelectedAnswerIndex(index);
    if (isTrueAnswer) {
      switch (grade) {
        case 'F':
          setGrade('D');
          break;
        case 'D':
          setGrade('C');
          break;
        case 'C':
          setGrade('B');
          break;
        case 'B':
          setGrade('A');
          break;
        default:
          setGrade('A');
          break;
      }
    }
  };

  const handleSubmit = () => {
    router.push(`/app/grade.tsx?grade=${grade}`);
  };

  const isLastQuestion = currentQuestionIndex === questions.length - 1;

  return (
    <Card className="w-[80vw] h-[80vh] ml-[10vw] mt-[10vh]">
      <div className="h-2 bg-gray-200 rounded-md mb-4">
        <div className="h-full bg-green-500 rounded-md" style={{ width: `${progress}%` }}></div>
      </div>

      <CardHeader>
        <CardTitle className="flex mt-[7vh] text-lg justify-center 2xl">{questions[currentQuestionIndex]}</CardTitle>
      </CardHeader>

      <CardContent className="flex justify-center flex-col items-center mt-[45vh]">
        <div className="flex flex-col items-start space-y-2">
          {answers[currentQuestionIndex].map((answer, index) => (
            <label key={index} className="flex items-center space-x-2 mt-[-37vh]">
              <input type="radio" name="answer" checked={selectedAnswerIndex === index} onChange={() => handleAnswerChange(index, index === 2)} />
              <span className="text-xl">{answer}</span>
            </label>
          ))}
        </div>

        <div className="flex justify-center space-x-96 mt-4">
          <Button className="bg-black" onClick={handleDecrementButtonClick}>Prev</Button>
          <Button className="bg-black" onClick={isLastQuestion ? handleSubmit : handleIncrementButtonClick}>
            {isLastQuestion ? 'Submit' : 'Next'}
          </Button>
        </div>
      </CardContent>
    </Card>
  )
}
