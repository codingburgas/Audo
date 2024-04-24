"use client"
import * as React from "react";
import { useState, useEffect } from "react";
import { Card } from "@/components/ui/card";
import Image from 'next/image';
import PieChart from "../components/pieChart";
import { Inter } from "next/font/google";
import {
  Accordion,
  AccordionContent,
  AccordionItem,
  AccordionTrigger,
} from "@/components/ui/accordion"
import { useRouter } from "next/navigation";
import Link from "next/link";
import {
  ContextMenu,
  ContextMenuContent,
  ContextMenuItem,
  ContextMenuLabel,
  ContextMenuPortal,
  ContextMenuSeparator,
  ContextMenuSub,
  ContextMenuSubTrigger,
  ContextMenuTrigger,
  ContextMenuSubContent
} from "@/components/ui/context-menu"
import TypingAnimation from "./typewriter"


const inter = Inter({ subsets: ["latin"] });


export default function Home() {
  const [total, setTotal] = useState(0);
  const router = useRouter();
  const getTotalStorageTests = () => {
    let totalStorageTests =  localStorage.getItem('totalTests');
    return totalStorageTests;
    
  };

  // calculate result
  const calculateResult = () => {
    // get finished tests:
    let finishedTests: any = getTotalStorageTests();
    if(localStorage.getItem('totalTests') && localStorage.getItem('totalTests') !== '0') {
      // get all tests
          
      let intFinishedTests = parseInt(finishedTests);
      // calcutate  result: 10 tests, finished: 2 = 20%
      let result = (intFinishedTests / 8) * 100;
      setTotal(result);
    }
    else {
      setTotal(0);
    }
  };

  useEffect(() => {
    calculateResult();
  }, [])

  return (
    <ContextMenu>
      <ContextMenuTrigger>
          <div className="mt-10 ml-6 flex flex-row">
          <div>

            
        <svg width="153" height="77" viewBox="0 0 153 77" fill="none" xmlns="http://www.w3.org/2000/svg">
          <g clip-path="url(#clip0_235_2)">
          <path d="M56.7936 28.2167C56.7936 28.2167 61.8568 26.6541 63.7196 26.2935C65.5825 25.933 66.6811 25.7406 68.4962 25.0435C70.3591 24.3223 72.6996 22.856 73.5116 22.5435C74.3236 22.255 74.3236 22.3511 75.8522 22.0867C77.7628 21.7502 80.3899 19.7309 81.393 20.3078C81.9662 20.6684 83.4947 22.88 84.1634 21.9665C84.45 21.5819 85.071 20.9569 85.6919 21.1973C86.3606 21.4617 86.2173 21.4136 86.8861 22.6396C87.5548 23.8656 87.8414 23.7935 88.7012 24.2262C89.6087 24.6348 88.94 24.4425 89.8953 25.4041C90.8984 26.3657 92.8568 27.4474 93.5733 28.0244C94.0509 28.4571 94.4331 28.7936 94.5764 28.9138C92.4747 28.5772 88.5101 28.0003 83.9246 27.6157C83.4947 27.207 83.4469 26.5339 83.3514 26.2935C82.9693 25.332 80.4854 25.6204 81.3452 24.8272C81.6318 24.5147 85.5964 22.6877 84.2589 22.7838C83.4469 22.856 82.014 23.0002 81.7274 23.0723C77.6673 23.9377 82.6827 21.053 78.5748 21.9425C78.1927 22.0386 77.0941 21.9425 76.4253 22.3031C75.8044 22.6636 74.9446 22.2309 74.1804 22.6636C73.4161 23.0964 73.8938 23.2887 72.6518 23.7935C71.4577 24.2983 71.5055 24.3223 70.4546 24.6829C69.4515 25.0435 69.3082 25.5483 68.4007 25.7166C67.5409 25.8849 65.8691 26.2935 65.2959 26.2935C64.6749 26.2935 62.2867 27.0147 62.0001 27.1589C61.7612 27.3272 56.7936 28.2167 56.7936 28.2167Z" fill="black"/>
          <path d="M58.4653 28.7696C58.4653 28.7696 68.5917 27.3993 77.8583 27.7359C87.0771 28.0724 95.9615 29.683 95.9615 29.683L92.5224 30.1398C85.0709 28.7215 77.3806 28.2888 77.3806 28.2888C77.3806 28.2888 84.7365 29.4667 88.9877 30.6206L83.208 31.3658C83.208 31.3658 77.2373 29.5628 73.225 28.9859C69.2604 28.409 58.4653 28.7696 58.4653 28.7696Z" fill="black"/>
          <path d="M47.7617 56.5635L45.0385 50.9471H34.6795L31.9563 56.5635H27.4176L38.0969 36.4089H41.7813L52.4072 56.5635H47.7617ZM40.0192 40.3055L35.8009 48.6629H43.9171L40.0192 40.3055ZM64.9167 56.8054C61.6773 56.8054 59.1499 56.3262 57.3344 55.3677C55.5189 54.4092 54.6111 53.0252 54.6111 51.2158V36.4089H59.2567V51.1621C59.2567 51.5383 59.3545 51.9234 59.5503 52.3176C59.7461 52.7118 60.0576 53.0611 60.4848 53.3656C60.9119 53.6702 61.4815 53.921 62.1935 54.1181C62.9054 54.3152 63.7775 54.4137 64.8099 54.4137C65.9846 54.4137 66.9635 54.3286 67.7467 54.1584C68.5299 53.9882 69.1529 53.7419 69.6156 53.4194C70.0783 53.0969 70.4077 52.7118 70.6035 52.2639C70.7993 51.8159 70.8972 51.3233 70.8972 50.7858V36.4089H75.4893V51.2158C75.4893 53.0611 74.6171 54.454 72.8728 55.3945C71.1285 56.3351 68.4764 56.8054 64.9167 56.8054ZM99.6392 52.2907C99.39 52.864 99.0252 53.4058 98.5446 53.9164C98.0641 54.427 97.4322 54.8793 96.6491 55.2735C95.8659 55.6676 94.9137 55.9812 93.7923 56.214C92.671 56.4469 91.3628 56.5634 89.8677 56.5634H80.0961V36.4088H89.4939C92.1281 36.4088 94.3797 36.7447 96.2486 37.4165C98.1175 38.0883 99.3189 39.2125 99.8528 40.789C99.924 41.0757 99.9952 41.5102 100.066 42.0924C100.138 42.6746 100.191 43.3375 100.227 44.081C100.262 44.8244 100.28 45.6083 100.28 46.4323C100.28 47.2564 100.253 48.0492 100.2 48.8106C100.146 49.5719 100.075 50.2617 99.9863 50.8798C99.8973 51.4978 99.7816 51.9683 99.6392 52.2907ZM89.0666 38.7737L84.4745 38.7738V54.145H89.7608C91.1491 54.145 92.2882 53.8987 93.1782 53.406C94.0682 52.9133 94.7267 52.3714 95.1538 51.7802C95.2963 51.5831 95.412 51.2069 95.501 50.6515C95.59 50.0962 95.6612 49.4557 95.7146 48.7301C95.768 48.0046 95.7947 47.2387 95.7947 46.4325C95.7947 45.6263 95.7769 44.865 95.7413 44.1483C95.7056 43.4317 95.6433 42.8047 95.5543 42.2672C95.4653 41.7298 95.3674 41.3625 95.2606 41.1654C95.047 40.8788 94.8068 40.5921 94.5398 40.3055C94.2728 40.0189 93.9079 39.7591 93.4451 39.5262C92.9824 39.2933 92.4039 39.1097 91.7098 38.9753C91.0156 38.8409 90.1346 38.7737 89.0666 38.7737ZM114.551 56.8054C111.205 56.8054 108.687 56.3306 106.996 55.3811C105.305 54.4316 104.46 53.0432 104.46 51.2158V41.8103C104.46 39.965 105.314 38.5722 107.023 37.6316C108.731 36.6911 111.454 36.2208 115.192 36.2208C118.61 36.2208 121.155 36.6956 122.828 37.6451C124.501 38.5945 125.338 39.965 125.338 41.7566V51.2158C125.338 53.0611 124.519 54.454 122.881 55.3945C121.244 56.3351 118.467 56.8054 114.551 56.8054ZM120.745 41.7297C120.745 41.3356 120.648 40.9459 120.452 40.5608C120.256 40.1756 119.945 39.8308 119.517 39.5261C119.09 39.2215 118.521 38.9753 117.809 38.7871C117.097 38.599 116.207 38.505 115.139 38.505C113.929 38.505 112.932 38.5856 112.149 38.7468C111.366 38.9081 110.742 39.1454 110.28 39.459C109.817 39.7725 109.497 40.1442 109.319 40.5742C109.141 41.0042 109.052 41.4879 109.052 42.0253V51.0814C109.052 51.4935 109.141 51.9011 109.319 52.3042C109.497 52.7073 109.79 53.07 110.2 53.3925C110.609 53.715 111.17 53.9748 111.882 54.1718C112.594 54.3689 113.484 54.4674 114.552 54.4674C115.762 54.4674 116.768 54.3913 117.568 54.239C118.369 54.0867 119.001 53.8672 119.464 53.5806C119.927 53.2939 120.256 52.9446 120.452 52.5326C120.648 52.1205 120.746 51.6637 120.746 51.162L120.745 41.7297Z" fill="black"/>
          </g>
          <defs>
          <clipPath id="clip0_235_2">
          <rect width="153" height="77" fill="white"/>
          </clipPath>
          </defs>
        </svg>
      <div className="flex flex-row items-end">
            <div className="max-w-fit flex items-start flex-col max-h-fit object-fit ml-24">
              <h1 className={`${inter.className} font-semibold text-[2.8rem] mt-14`}>
               <TypingAnimation text = "Aleksandur Kolev's Available Tests" speed = {100} />
              </h1>
              <div className="flex flex-row">
              <p className={`mr-1 ${inter.className} opacity-75 text-[1.4rem] font-semibold`}>9 GRADE</p>
              <p  className={`${inter.className} opacity-75 text-[#121212] text-[1.4rem] font-semibold`}>STUDENT</p>
              </div>
            </div>
      </div>
            <Accordion type="single" collapsible className="mt-12 ml-32 text-[1.8rem]">
            <AccordionItem value="item-1" className="max-w-fit">
              <AccordionTrigger className="max-w-fit">Natural Sciences</AccordionTrigger>
              <AccordionContent className="max-w-fit">
                <Link href="/history" style={{cursor: "pointer"}} className="text-[1.6rem]">Math</Link>
              </AccordionContent>
            </AccordionItem>
            <AccordionItem value="item-2">
              <AccordionTrigger>Languages</AccordionTrigger>
              <AccordionContent>
                <h1 className="text-[1.6rem]">Math</h1>
              </AccordionContent>
            </AccordionItem>
            <AccordionItem value="item-3">
              <AccordionTrigger>Social Sciences</AccordionTrigger>
              <AccordionContent>
                <h1 className="text-[1.6rem]">Math</h1>
              </AccordionContent>
            </AccordionItem>
            <AccordionItem value="item-4">
              <AccordionTrigger>Developer</AccordionTrigger>
              <AccordionContent>
                <h1 className="text-[1.6rem]">Math</h1>
              </AccordionContent>
            </AccordionItem>
          </Accordion>
           

            </div>
            <div className="ml-[30vw] mt-[10vh]">

            
    <PieChart total={total} />
    {total !== 0 ? (
                <div className="font-semibold text-2xl mt-10 mb-5 -ml-[2rem]">Total Finished Tests: {total}%</div>
            ) : (
                <div>0%</div>
            )}
    </div>
            </div>
          <ContextMenuContent
              className="min-w-[18rem] bg-[#fdfdff] rounded-lg overflow-hidden p-[0.5rem] shadow-lg border-solid border-[0.1rem] border-[#CCCCCC] border-opacity-60"
              sideOffset={5}
              align="end"
            >
              <ContextMenuLabel className={`pl-[2.3rem] text-[1.25rem] leading-[25px] tracking-wide ${inter.className} font-medium text-[#333] opacity-80`}>
                General
              </ContextMenuLabel>
              <ContextMenuItem className={`group text-[1.4rem] leading-none text-[#333333] rounded-[0.3rem] flex items-center h-[2.5rem] px-[0.5rem] relative pl-[2.5rem] select-none outline-none data-[disabled]:text-mauve8 data-[disabled]:pointer-events-none data-[highlighted]:bg-violet9 data-[highlighted]:text-[#007BFF] tracking-wider ${inter.className}`}>
                Back{' '}
                <div className="ml-auto pl-5 text-mauve11 group-data-[highlighted]:text-[#007BFF] group-data-[disabled]:text-mauve8 tracking-wider">
                  Ctrl+B
                </div>
              </ContextMenuItem>
              <ContextMenuItem className={`group text-[1.4rem] leading-none text-[#333333] rounded-[0.3rem] flex items-center h-[2.5rem] px-[0.5rem] relative pl-[2.5rem] select-none outline-none data-[disabled]:text-mauve8 data-[disabled]:pointer-events-none data-[highlighted]:bg-violet9 data-[highlighted]:text-[#007BFF] tracking-wider ${inter.className}`}>
                    Save{' '}
                <div className="ml-auto pl-5 text-mauve11 group-data-[highlighted]:text-[#007BFF] group-data-[disabled]:text-mauve8 tracking-wider">
                  Ctrl+S
                </div>
              </ContextMenuItem>
              <ContextMenuItem className={`group text-[1.4rem] leading-none text-[#333333] rounded-[0.3rem] flex items-center h-[2.5rem] px-[0.5rem] relative pl-[2.5rem] select-none outline-none data-[disabled]:text-mauve8 data-[disabled]:pointer-events-none data-[highlighted]:bg-violet9 data-[highlighted]:text-[#007BFF] tracking-wider ${inter.className} mb-2`} onClick={()=>location.reload()}>
                Reload{' '}
                <div className="ml-auto pl-5 text-mauve11 group-data-[highlighted]:text-[#007BFF] group-data-[disabled]:text-mauve8 tracking-wider">
                  Ctrl+R
                </div>
              </ContextMenuItem>
                <ContextMenuSeparator className="h-[1px] bg-[#333333] bg-opacity-40 m-[5px]" />
                <ContextMenuLabel className={`pl-[25px] text-[1.25rem] leading-[25px] tracking-wide ${inter.className} font-medium text-[#333] opacity-80`}>
                Low-level
              </ContextMenuLabel>
                <ContextMenuItem className={`group text-[1.4rem] leading-none text-[#333333] rounded-[0.3rem] flex items-center h-[2.5rem] px-[0.5rem] relative pl-[2.5rem] select-none outline-none data-[disabled]:text-mauve8 data-[disabled]:pointer-events-none data-[highlighted]:bg-violet9 data-[highlighted]:text-[#007BFF] tracking-wider ${inter.className}`}>
                Change Mode{' '}
                <div className="ml-auto pl-5 text-mauve11 group-data-[highlighted]:text-[#007BFF] group-data-[disabled]:text-mauve8 tracking-wider">
                  Ctrl+G
                </div>
              </ContextMenuItem>
                <ContextMenuItem className={`group text-[1.4rem] leading-none text-[#333333] rounded-[0.3rem] flex items-center h-[2.5rem] px-[0.5rem] relative pl-[2.5rem] select-none outline-none data-[disabled]:text-mauve8 data-[disabled]:pointer-events-none data-[highlighted]:bg-violet9 data-[highlighted]:text-[#007BFF] tracking-wider ${inter.className}`} >
                Show Editor{' '}
                <div className="ml-auto pl-5 text-mauve11 group-data-[highlighted]:text-[#007BFF] group-data-[disabled]:text-mauve8 tracking-wider">
                  Ctrl+E
                </div>
              </ContextMenuItem>
                <ContextMenuItem className={`group text-[1.4rem] leading-none text-[#333333] rounded-[0.3rem] flex items-center h-[2.5rem] px-[0.5rem] relative pl-[2.5rem] select-none outline-none data-[disabled]:text-mauve8 data-[disabled]:pointer-events-none data-[highlighted]:bg-violet9 data-[highlighted]:text-[#007BFF] tracking-wider ${inter.className} mb-3`}>
                Toggle Pen{' '}
                <div className="ml-auto pl-5 text-mauve11 group-data-[highlighted]:text-[#007BFF] group-data-[disabled]:text-mauve8 tracking-wider">
                  P
                </div>
              </ContextMenuItem>
            </ContextMenuContent>
      </ContextMenuTrigger>
  </ContextMenu>
  
    );
    
}