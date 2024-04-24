"use client"
import * as React from "react";
import { Card } from "@/components/ui/card";
import Image from 'next/image';
export default function Home() {

  const tests = [
    { title: "History", url: "/history" },
    { title: "Physics", url: "/physics" },
    { title: "Math", url: "/math" },
    { title: "Math", url: "/math" },
    { title: "Math", url: "/math" },
    { title: "Math", url: "/math" },
    { title: "Math", url: "/math" },
    { title: "Math", url: "/math" },
  ];

  return (
    
      <div className="w-[80vw] h-[80vh] ml-[10vw] mt-[10vh]">
        <div className="h-4 bg-white rounded-md mb-4"></div>
        <div className="h-full bg-white rounded-md flex flex-col items-center justify-center ">
          <Image 
            src="/logo.svg"
            width={500}
            height={500}
            alt="Logo"
            className="mx-auto"
          />
          <div className="">
          
            <div className="h-full  pl-[15vw] pr-[15vw] mb-5 ">
              <h2 className="text-3xl mb-10 font-semibold text-center bg-gradient-to-r from-indigo-300 via-slate-800 to-indigo-300 bg-clip-text text-transparent mb-4">
              Your Path to Knowledge
              </h2>
              <p className="text-lg text-gray-700 mb-8">
                Audo’s main purpose is to provide a comprehensive online school platform, ideally tailored for educators, making note-taking and class management easier and more efficient. With our user-friendly interface, teachers and students can create classes, organize their notes, and grade participants with the click of a button. The secure invitation-only access provides privacy and control. Audo fills a gap in online educational apps with its security, easy navigation, organization, and appeal.
              </p>
              <div className="grid grid-cols-2 md:grid-cols-4 gap-4">
                {tests.map((test, index) => (
                  <a key={index} href={test.url} className="bg-gradient-to-r from-indigo-300 via-slate-800 to-indigo-300 text-white py-3 px-6 rounded-md text-center transition duration-300 hover:bg-blue-600 text-lg font-medium">
                    {test.title}
                  </a>
                ))}
              </div>
            </div>
          </div>
        </div>
      </div>
    );
    
}