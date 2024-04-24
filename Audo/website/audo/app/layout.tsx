"use client"
import type { Metadata } from "next";
import { Inter } from "next/font/google";
import { SessionProvider } from "next-auth/react";
import "./globals.css";

const inter = Inter({ subsets: ["latin"] });


export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
    <html lang="en" className={`h-screen w-screen text-[62.5%] `}>
      <SessionProvider>
        <body className={`${inter.className} bg-[#fefefe]`}>{children}</body>
      </SessionProvider>
    </html>
  );
}
