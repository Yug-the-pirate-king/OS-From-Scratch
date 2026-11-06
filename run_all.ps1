# ==============================================================================
# Os from scratch - Windows PowerShell Benchmark Runner
# Author: Yug Shah (TYCSE)
# ==============================================================================

Write-Host "==========================================================" -ForegroundColor Cyan
Write-Host "          OS FROM SCRATCH - LAB BENCHMARK RUNNER          " -ForegroundColor Yellow
Write-Host "                Author: Yug Shah (TYCSE)                  " -ForegroundColor Green
Write-Host "==========================================================" -ForegroundColor Cyan

Write-Host "`n>>> Testing Experiment 4: CPU Scheduling (FCFS) <<<" -ForegroundColor Yellow
gcc Experiment_04_CPU_Scheduling/fcfs.c -o exp4_fcfs.exe
Get-Content Experiment_04_CPU_Scheduling/input_fcfs.txt | .\exp4_fcfs.exe
Remove-Item exp4_fcfs.exe -Force -ErrorAction SilentlyContinue

Write-Host "`n>>> Testing Experiment 5: Page Replacement (FIFO) <<<" -ForegroundColor Yellow
gcc Experiment_05_Page_Replacement/fifo.c -o exp5_fifo.exe
Get-Content Experiment_05_Page_Replacement/input_pages.txt | .\exp5_fifo.exe
Remove-Item exp5_fifo.exe -Force -ErrorAction SilentlyContinue

Write-Host "`n>>> Testing Experiment 8: Banker's Deadlock Avoidance <<<" -ForegroundColor Yellow
gcc Experiment_08_Producer_Consumer_Bankers/bankers_algorithm.c -o exp8_banker.exe
Get-Content Experiment_08_Producer_Consumer_Bankers/input_banker.txt | .\exp8_banker.exe
Remove-Item exp8_banker.exe -Force -ErrorAction SilentlyContinue

Write-Host "`n==========================================================" -ForegroundColor Cyan
Write-Host " All test benchmarks executed successfully!" -ForegroundColor Green
Write-Host " Author: Yug Shah (TYCSE) | Repo: Os from scratch" -ForegroundColor Yellow
Write-Host "==========================================================" -ForegroundColor Cyan

