"use client";
import { signIn } from "next-auth/react";

export default function AuthPage() {


return (
<button
  onClick={() => {
    signIn(
      'azure-ad',
      { callbackUrl: '/dashboard' },
      { prompt: 'login' },
    );
  }}
>
  Log in
</button>
    )
}