import heapq

# ==========================================
# 1. Recursive Binary Search
# ==========================================
def binary_search(arr, low, high, key):
    # Base case: agar search space khatam ho jaye
    if low > high:
        return -1
    
    mid = (low + high) // 2
    
    if arr[mid] == key:
        return mid  # Same -> found
    elif key < arr[mid]:
        # Key chhoti -> left side
        return binary_search(arr, low, mid - 1, key)
    else:
        # Key badi -> right side
        return binary_search(arr, mid + 1, high, key)

# ==========================================
# 2. Euclid's GCD Algorithm
# ==========================================
def euclid_gcd(a, b):
    mod_count = 0
    assign_count = 0
    
    while b != 0:
        r = a % b
        mod_count += 1
        
        a = b
        b = r
        assign_count += 2
        
    return a, mod_count, assign_count

# ==========================================
# 3 & 9. Matrix Multiplication (Generic for 3x3 and 4x4)
# ==========================================
def matrix_multiplication(A, B, size):
    # N matrix initialize kardi zero se
    C = [[0] * size for _ in range(size)]
    
    outer = 0
    inner = 0
    add = 0
    mul = 0
    
    for i in range(size):
        outer += 1
        for j in range(size):
            for k in range(size):
                C[i][j] += A[i][k] * B[k][j]
                
                mul += 1
                inner += 1
                
                if k > 0:
                    add += 1
                    
    return C, outer, inner, mul, add

# ==========================================
# 4. Merge Sort
# ==========================================
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]
        
        # Recursively sort both halves
        merge_sort(left_half)
        merge_sort(right_half)
        
        i = j = k = 0
        
        # Merge step
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1
            
        # Bachi hui items ko copy karo
        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1
            
        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

# ==========================================
# 5. Task Scheduling (Shortest Job First - SJF)
# ==========================================
def sjf_scheduling(jobs):
    # Rule: Shortest service time first
    sorted_jobs = sorted(jobs.items(), key=lambda x: x[1])
    
    total_time = 0
    current_time = 0
    
    print("\n--- 5. SJF Scheduling ---")
    print("Order of execution:")
    for job_name, duration in sorted_jobs:
        current_time += duration
        total_time += current_time
        print(f"{job_name} completes at: {current_time}")
        
    avg_time = total_time / len(jobs)
    print(f"Total time = {total_time}")
    print(f"Average = {avg_time}")

# ==========================================
# 6. Quick Sort
# ==========================================
def quick_sort(arr, low, high):
    if low < high:
        pivot = arr[high] # Last element as pivot
        i = low - 1
        
        for j in range(low, high):
            # Smaller elements left side pe rakho
            if arr[j] < pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i] # Swap
                
        # Pivot ko uski sahi jagah pe place karo
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        pi = i + 1
        
        # Recursively sort
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

# ==========================================
# 7. Fractional Knapsack
# ==========================================
def fractional_knapsack(profits, weights, capacity):
    # Ratio = Profit / Weight calculate karo
    items = []
    for i in range(len(profits)):
        ratio = profits[i] / weights[i]
        items.append({"profit": profits[i], "weight": weights[i], "ratio": ratio, "id": f"P{i+1}"})
        
    # Highest ratio first (descending order)
    items.sort(key=lambda x: x["ratio"], reverse=True)
    
    total_profit = 0.0
    rem_capacity = capacity
    
    print("\n--- 7. Fractional Knapsack ---")
    for item in items:
        if item["weight"] <= rem_capacity:
            total_profit += item["profit"]
            rem_capacity -= item["weight"]
            print(f"Took full {item['id']} (Weight: {item['weight']})")
        else:
            # Agar jagah kam hai toh fraction lo
            fraction = rem_capacity / item["weight"]
            total_profit += item["profit"] * fraction
            print(f"Took {fraction*100}% of {item['id']} (Weight: {rem_capacity})")
            break # capacity full
            
    print(f"Optimal Profit = {total_profit}")

# ==========================================
# 8. Selection Sort
# ==========================================
def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        min_idx = i
        # Har round mein minimum element find karo
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        # Aur current position par swap kardo
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

# ==========================================
# 10. Bubble Sort
# ==========================================
def bubble_sort(arr):
    n = len(arr)
    exchange = 0
    comparison = 0
    outer = 0
    inner = 0
    
    for i in range(n - 1):
        outer += 1
        for j in range(n - 1 - i):
            inner += 1
            comparison += 1
            
            # Adjacent elements compare karo
            if arr[j] > arr[j + 1]:
                # Swap
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                exchange += 1
                
    return outer, inner, comparison, exchange

# ==========================================
# 11. Huffman Coding
# ==========================================
def huffman_coding(frequencies):
    # Min-Heap use karke sabse chhoti 2 frequencies combine karenge
    heap = frequencies.copy()
    heapq.heapify(heap)
    
    total_cost = 0
    
    while len(heap) > 1:
        # Extract two smallest
        min1 = heapq.heappop(heap)
        min2 = heapq.heappop(heap)
        
        merged_freq = min1 + min2
        total_cost += merged_freq
        
        heapq.heappush(heap, merged_freq)
        
    return total_cost