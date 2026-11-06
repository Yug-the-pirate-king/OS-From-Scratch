#!/bin/bash
# ==============================================================================
# Os from scratch - Automated Test Runner
# Author: Yug Shah (TYCSE)
# ==============================================================================

echo "=========================================================="
echo "          OS FROM SCRATCH - LAB BENCHMARK RUNNER          "
echo "                Author: Yug Shah (TYCSE)                  "
echo "=========================================================="

echo -e "\n>>> Testing Experiment 4: CPU Scheduling (FCFS) <<<"
gcc Experiment_04_CPU_Scheduling/fcfs.c -o exp4_fcfs
./exp4_fcfs < Experiment_04_CPU_Scheduling/input_fcfs.txt
rm -f exp4_fcfs

echo -e "\n>>> Testing Experiment 5: Page Replacement (FIFO) <<<"
gcc Experiment_05_Page_Replacement/fifo.c -o exp5_fifo
./exp5_fifo < Experiment_05_Page_Replacement/input_pages.txt
rm -f exp5_fifo

echo -e "\n>>> Testing Experiment 8: Banker's Deadlock Avoidance <<<"
gcc Experiment_08_Producer_Consumer_Bankers/bankers_algorithm.c -o exp8_banker
./exp8_banker < Experiment_08_Producer_Consumer_Bankers/input_banker.txt
rm -f exp8_banker

echo -e "\n=========================================================="
echo " All test benchmarks executed successfully!"
echo " Author: Yug Shah (TYCSE) | Repo: Os from scratch"
echo "=========================================================="

