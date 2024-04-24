import { NextResponse } from 'next/server';
import { NextApiRequest, NextApiResponse } from 'next';

export async function POST(req: Request, res: NextApiResponse) {
const { email, password } = await req.json();
console.log(`Params server fetch: ${email} ${password}`)
let response = await fetch("http://localhost:45098/api/login", {
    method: "POST", 
    headers: {
        "Content-Type": "application/json",
    },
    body: JSON.stringify({
        email: email,
        password: password,
    })
})

if (response.ok) {
    const { token } = await response.json();
    return NextResponse.json({token : token}, {status: 200});
} 
else 
    console.log('Response failed', response.status);

}