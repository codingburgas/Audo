import { useRef, useEffect } from "react";
import Chart from "chart.js/auto";

export default function PieChart({ total } : {total : number}) {
    const chartRef = useRef(null);

    useEffect(() => {
        if (chartRef.current) {
            if (chartRef.current.chart) {
                chartRef.current.chart.destroy();
            }
            const context = chartRef.current.getContext("2d");
            const newChart = new Chart(context, {
                type: "pie",
                data: {
                      labels: [
                        'Finished',
                        'Remaining tests',
                    ],
                    datasets: [
                        {
                            label: "% Finished Test", 
                            data: [total, 100 - total],
                            backgroundColor: [
                                "#c2cbed",
                                "#e6e6e8",
                            ],
                            borderWidth: 1,
                        },
                        
                    ],
                    
                },
               
            });
            chartRef.current.chart = newChart;
        }
    }, [total]);
    return (
        <div style={{ position: "relative", width: "40rem", height: "40rem" }}>
            <canvas ref={chartRef} className="ml-52 mt-24"/>
        </div>
    );
}