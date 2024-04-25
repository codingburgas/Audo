"use client"
import { useEffect, useState } from 'react';
import { CardTitle, CardDescription, CardHeader, CardContent, Card } from "@/components/ui/card"
import { Label } from "@/components/ui/label"
import { Input } from "@/components/ui/input"
import { Button } from "@/components/ui/button"
import Cookies from 'js-cookie';
import { useRouter } from 'next/navigation';
import { AppRouterInstance } from 'next/dist/shared/lib/app-router-context.shared-runtime';
import React from 'react';
const request = async ({email, password} : {email : string | null, password : string | null}) => {
  console.log(`Params client fetch: ${email} ${password}`)
  try {
    const response = await fetch("http://localhost:3000/api/audo/login", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({
        email : email,
        password: password,
      }),
    });

    if (!response.ok) {
      throw new Error(`HTTP error! status: ${response.status}`);
    }

    const { token, userInfo } = await response.json();
    const name = String(userInfo.fname) + " " + String(userInfo.lname);
    Cookies.set('token', token);
    Cookies.set('name', name);
    Cookies.set('status', userInfo.status);

  } catch (error) {
    console.error('There was a problem with the fetch operation: ', error);
  }
}

const submitForm = async ({email, password, router} : {email : string | null, password: string | null, router : AppRouterInstance | null}) =>{
  await request({email, password});
  if (router) {
    router.push('/');
  }
}

export default function AuthPage() {
    useEffect(() => {
    Cookies.remove("token");
    Cookies.remove("name");
    Cookies.remove("status");
    Cookies.set("counter", 0);
  }, []);
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const router = useRouter();
  return (
    <div className="w-screen h-screen flex flex-col justify-center items-center">
      <Card className="mx-auto max-w-sm scale-[2]">
        <CardHeader className="space-y-1">
          <CardTitle className="text-2xl font-bold">Log in Audo</CardTitle>
          <CardDescription>Enter your email and password to login to your account</CardDescription>
        </CardHeader>
        <CardContent>
          <div className="space-y-4">
            <div className="space-y-2">
              <Label htmlFor="email">Email</Label>
              <Input id="email" placeholder="johndoe@vscpi.live" required type="email" className="bg-[#fefefe] tracking-wider" value={email} onChange={e => setEmail(e.target.value)} />
            </div>
            <div className="space-y-2">
              <Label htmlFor="password">Password</Label>
              <Input id="password" required type="password" className="bg-[#fefefe] tracking-wider" value={password} onChange={e => setPassword(e.target.value)} />
            </div>
            <Button className="w-full" type="submit" onClick={ () => submitForm({email, password, router})}>
              Login
            </Button>
          </div>
        </CardContent>
      </Card>
    </div>
  )
}