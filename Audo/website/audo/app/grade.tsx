"use client"
import * as React from "react";
import { useRouter } from "next/router";

export default function GradePage() {
  const router = useRouter();
  const { grade } = router.query;

  return (
    <div className="flex justify-center items-center h-screen">
      <div className="bg-gray-200 p-8 rounded-lg">
        <h1 className="text-4xl font-bold mb-4">Your Grade</h1>
        <p className="text-2xl font-semibold">{grade}</p>
      </div>
    </div>
  );
}
