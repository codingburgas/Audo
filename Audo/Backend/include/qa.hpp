#pragma once
#include <unordered_map>
#include <string>

static const std::unordered_map<std::string, std::string> mathQA = {
	{"What is 5+35+3?", "43"},
	{"Solve for x in the equation 2x + 4 = 10.", "3"},
	{"What is the square root of 49?", "7"},
	{"What is 3 × 4?", "12"},
	{"Solve for y in the equation 2y − 5 = 7", "12"},
	{"What is 1/2 + 1/3?", "2/3"},
	{"What is 9−5?", "4"},
	{"Solve for x in the equation 3x − 2 = 10.", "4"},
	{"What is 7 × 6?", "42"},
	{"What is 3/4 x 8?", "6"},
	{"What is 20 ÷ 5?", "4"}
};

static const std::unordered_map<std::string, std::string> physicsQA = {
	{"What is the unit of measurement for force?", "Newton"},
	{"What is Newton's first law of motion also known as?", "Law of inertia"},
	{"What is the SI unit of power?", "Watt"},
	{"What is the acceleration due to gravity on Earth?", "9.8 m/s^2"},
	{"What is the law of conservation of energy?", "Energy cannot be created or destroyed, only transformed from one form to another."},
	{"What is the formula for calculating kinetic energy?", "0.5 * mass * velocity^2"},
	{"What is the principle behind the operation of a lever?", "A rigid bar that pivots around a fixed point."},
	{"What is the relationship between force, mass, and acceleration according to Newton's second law?", "Force equals mass times acceleration (F=ma)."},
	{"What is the unit of measurement for electrical resistance?", "Ohm"},
	{"What is the formula for calculating work?", "Force times distance (W=Fd)"},
	{"What is the phenomenon responsible for the bending of light?", "Refraction"}
};

static const std::unordered_map<std::string, std::string> historyQA = {
	{"What were the main causes of World War I?", "It was caused by a complex web of alliances, militarism, imperialism, and nationalism."},
	{"How did the Treaty of Versailles contribute to the outbreak of World War II?", "It strengthened Germany's economy and military power."},
	{"Describe the significance of the Industrial Revolution in shaping modern society.", "It led to urbanization, technological advancements, and the rise of capitalism."},
	{"What were the key events and consequences of the French Revolution?", "It had no long-term consequences."},
	{"Explain the impact of imperialism on the colonized regions and the colonial powers.", "It promoted democracy and human rights in the colonized regions."},
	{"What were the major factors leading to the rise of fascism in Europe during the 20th century?", "Economic instability, nationalism, and dissatisfaction with the Treaty of Versailles."},
	{"Discuss the significance of the Civil Rights Movement in the United States during the 20th century.", "It led to legal reforms, desegregation, and increased awareness of racial injustice."},
	{"How did the Cold War influence global politics and society?", "It caused global division, nuclear proliferation, and proxy wars."},
	{"Describe the origins and consequences of the Great Depression in the 1930s.", "It resulted in economic prosperity and growth."},
	{"What were the main causes and effects of the Russian Revolution of 1917?", "It had no lasting effects on Russian society."},
	{"Explain the role of technology in shaping warfare during World War I and World War II.", "It introduced tanks, airplanes, and chemical weapons, changing warfare."}
};