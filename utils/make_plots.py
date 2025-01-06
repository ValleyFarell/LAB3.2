import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('./plots/quick_sort/quick_sort_performance.csv')

def plot_sorting_performance(file_name, algorithm_name):
    data = pd.read_csv(file_name)
    plt.plot(data['Elements'], data['Time (ms)'], marker='o', label=algorithm_name)

plt.figure(figsize=(12, 8))

plot_sorting_performance('./plots/quick_sort/quick_sort_performance.csv', 'QuickSort')
plot_sorting_performance('./plots/shell_sort/shell_sort_performance.csv', 'ShellSort')
plot_sorting_performance('./plots/sel_sort/selection_sort_performance.csv', 'SelectionSort')

plt.title('Sorting Algorithm Performance')
plt.xlabel('Number of Elements')
plt.ylabel('Time (ms)')
plt.grid()
plt.legend()
plt.xticks(data['Elements'])
plt.yticks(range(0, 70001, 5000))

plt.show()

