import { useRef, useEffect } from "react";
import Chart from "chart.js/auto";

export default function PieChart({ total }) {
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
                    
                    datasets: [
                        {
                            label: "Total Finished Tests",
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
        <div style={{ position: "relative", width: "15rem", height: "15rem" }}>
            <canvas ref={chartRef} />
        </div>
    );
}
