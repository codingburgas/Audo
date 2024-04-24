import { useState, useEffect } from "react";
import "./typing.css"
const Typewriter = ({ text, speed } : {text : string, speed : number}) => {
  const [displayText, setDisplayText] = useState('');
  const [currentIndex, setCurrentIndex] = useState(0);
useEffect(() => {
  let intervalId : any;

  if (currentIndex < text.length) {
    intervalId = setInterval(() => {
      setDisplayText((prevText) => prevText + text[currentIndex]);
      setCurrentIndex((prevIndex) => prevIndex + 1);

      if (currentIndex === text.length - 1) {
        clearInterval(intervalId);
      }
    }, speed);
  }

  return () => clearInterval(intervalId);
}, [currentIndex, text, speed]);

  return <span id = "anim">{displayText}</span>;
};

export default Typewriter;