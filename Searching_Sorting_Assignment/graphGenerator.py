import matplotlib.pyplot as plt

algorithms = [
    "Selection Sort",
    "Bubble Sort",
    "Insertion Sort",
    "Quick Sort",
    "Heap Sort"
]
times = [5.444, 5.974, 1.936, 0.722, 0.818]  # Execution times in seconds

# Create bar chart
plt.figure(figsize=(10, 6))
bars = plt.bar(algorithms, times, color=['skyblue', 'lightgreen', 'salmon', 'purple', 'orange'])
plt.xlabel("Sorting Algorithm")
plt.ylabel("Time (seconds)")
plt.title("Sorting Random 50,000 Integers (Average Over 5 Cycles)")
plt.bar_label(bars, label_type="edge", padding=1)
plt.show()
