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
const request = async ({firstName, lastName, selectedOption, email, password, router} : {firstName : string, lastName : string, selectedOption : any, email : string | null, password: string | null, router : AppRouterInstance | null}) => {
  console.log(`Params client fetch: ${email} ${password}`)
  try {
    const response = await fetch("http://localhost:45098/api/register", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({
        email : email,
        fname : firstName,
        lname: lastName,
        school: "VSCPI",
        status: selectedOption
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

const submitForm = async ({firstName, lastName, selectedOption, email, password, router} : {firstName : string, lastName : string, selectedOption : any, email : string | null, password: string | null, router : AppRouterInstance | null}) =>{
  await request({firstName, lastName, selectedOption, email, password, router});
  if (router){
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
  const [firstName, setFirstName] = useState('John');
  const [lastName, setLastName] = useState('Doe');
  const [selectedOption, setSelectedOption] = useState('student');

  const router = useRouter();
  return (
    <div className="w-screen h-screen flex flex-col justify-center items-center">
      <Card className="mx-auto max-w-sm scale-[2]">
        <CardHeader className="space-y-1">
          <CardTitle className="text-2xl font-bold">Register</CardTitle>
          <CardDescription>Create your online Audo account to use anywhere, even in the app.</CardDescription>
        </CardHeader>
        <CardContent>
          <div className="space-y-4">
            <div className='flex'>
            <div>
            <Label htmlFor="fname">First name</Label>
             <Input id="fname" placeholder="John" required type="text" className="bg-[#fefefe] tracking-wider max-w-[90%]" onChange={e => setFirstName(e.target.value)}   />
             </div>
             <div>
            <Label htmlFor="lname">Last name</Label>
             <Input id="lname" placeholder="Doe" required type="text" className="bg-[#fefefe] tracking-wider max-w-[90%]" onChange={e => setLastName(e.target.value)}  />
             </div>
            </div>
            <div className="space-y-2">
              <Label htmlFor="email">Email</Label>
              <Input id="email" placeholder="johndoe@vscpi.live" required type="email" className="bg-[#fefefe] tracking-wider" value={email} onChange={e => setEmail(e.target.value)} />
            </div>
            <div className="space-y-2">
              <Label htmlFor="password">Password</Label>
              <Input id="password" required type="password" className="bg-[#fefefe] tracking-wider" value={password} onChange={e => setPassword(e.target.value)} />
            </div>
            <div className="space-y-2">
              <h1>Status:</h1>
             <select className=' bg-[#fefefe] text-sm' value={selectedOption} onChange={e => setSelectedOption(e.target.value)}>
                <option style={{fontSize: '17px'}} value="option1" className='pt-4'>teacher</option>
                <option style={{fontSize: '17px'}} value="option2" className='pt-4'>student</option>
            </select>
            </div>
            <Button className="w-full" type="submit" onClick={ () => submitForm({firstName, lastName, selectedOption, email, password, router})}>
              Register
            </Button>
          </div>
        </CardContent>
      </Card>
    </div>
  )
}