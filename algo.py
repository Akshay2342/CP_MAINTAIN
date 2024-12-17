# import heapq

# # Define a node for the priority queue
# class Node:
#     def __init__(self, node, time, danger):
#         self.node = node
#         self.time = time
#         self.danger = danger

#     def __lt__(self, other):
#         return self.time < other.time  # Compare nodes based on arrival time

# # Function to compute the earliest arrival times and the shortest safe path
# def tdssp(graph, danger_factor, vs, ve, T, Omega):
#     # Initialize arrival times and danger factors
#     arrival_time = {node: float('inf') for node in graph}
#     danger_factor_path = {node: float('inf') for node in graph}
#     arrival_time[vs] = 0
#     danger_factor_path[vs] = 0
    
#     # Priority queue for Dijkstra-like approach
#     pq = []
#     heapq.heappush(pq, Node(vs, 0, 0))
    
#     # Keep track of predecessors to reconstruct the path
#     predecessor = {vs: None}
    
#     while pq:
#         current = heapq.heappop(pq)
#         current_node = current.node
#         current_time = current.time
#         current_danger = current.danger
        
#         # If we've reached the destination, return the results
#         if current_node == ve:
#             return reconstruct_path(predecessor, ve), current_time
        
#         # Explore neighbors
#         for neighbor, (travel_time, danger) in graph[current_node].items():
#             new_time = current_time + travel_time
#             new_danger = max(current_danger, danger)
            
#             # Ensure the path is safe and has a lower arrival time
#             if new_time < arrival_time[neighbor] and new_danger <= Omega:
#                 arrival_time[neighbor] = new_time
#                 danger_factor_path[neighbor] = new_danger
#                 predecessor[neighbor] = current_node
#                 heapq.heappush(pq, Node(neighbor, new_time, new_danger))
    
#     # If no path found
#     return None, float('inf')

# # Helper function to reconstruct the path from the predecessor map
# def reconstruct_path(predecessor, destination):
#     path = []
#     current = destination
#     while current is not None:
#         path.append(current)
#         current = predecessor[current]
#     return path[::-1]

# # Example graph with time-dependent edge delays and danger factors
# def example_graph():
#     # Graph format: node -> {neighbor: (travel_time, danger_factor)}
#     graph = {
#         'A': {'B': (5, 0.1), 'C': (10, 0.4)},
#         'B': {'C': (3, 0.2), 'D': (7, 0.2)},
#         'C': {'D': (1, 0.3)},
#         'D': {}
#     }
    
#     danger_factor = {
#         'A': {'B': 0.1, 'C': 0.4},
#         'B': {'C': 0.2, 'D': 0.6},
#         'C': {'D': 0.3},
#         'D': {}
#     }
    
#     return graph, danger_factor

# # Run an example
# if __name__ == "__main__":
#     graph, danger_factor = example_graph()
#     source = 'A'
#     destination = 'D'
#     T = (0, 60)  # Time interval
#     Omega = 0.5  # Safety threshold
    
#     path, time = tdssp(graph, danger_factor, source, destination, T, Omega)
    
#     if path:
#         print(f"The shortest safe path from {source} to {destination} is: {path}")
#         print(f"Total travel time: {time}")
#     else:
#         print("No safe path exists within the given danger threshold.")



import heapq

# Define a node for the priority queue
class Node:
    def __init__(self, node, time, danger):
        self.node = node
        self.time = time
        self.danger = danger

    def __lt__(self, other):
        return self.time < other.time  # Compare nodes based on arrival time

# Function to compute the earliest arrival times and the shortest safe path
def tdssp(graph, danger_factor, vs, ve, T, Omega):
    # Initialize arrival times and danger factors
    arrival_time = {node: float('inf') for node in graph}
    danger_factor_path = {node: float('inf') for node in graph}
    arrival_time[vs] = 0
    danger_factor_path[vs] = 0
    
    # Priority queue for Dijkstra-like approach
    pq = []
    heapq.heappush(pq, Node(vs, 0, 0))
    
    # Keep track of predecessors to reconstruct the path
    predecessor = {vs: None}
    
    while pq:
        current = heapq.heappop(pq)
        current_node = current.node
        current_time = current.time
        current_danger = current.danger
        
        # If we've reached the destination, return the results
        if current_node == ve:
            return reconstruct_path(predecessor, ve), current_time
        
        # Explore neighbors
        for neighbor, (travel_time_func, danger) in graph[current_node].items():
            # Get travel time based on the current time (time-dependent)
            new_travel_time = travel_time_func(current_time)  # This is dynamic
            
            new_time = current_time + new_travel_time
            new_danger = max(current_danger, danger)
            
            # Ensure the path is safe and has a lower arrival time
            if new_time < arrival_time[neighbor] and new_danger <= Omega:
                arrival_time[neighbor] = new_time
                danger_factor_path[neighbor] = new_danger
                predecessor[neighbor] = current_node
                heapq.heappush(pq, Node(neighbor, new_time, new_danger))
    
    # If no path found
    return None, float('inf')

# Helper function to reconstruct the path from the predecessor map
def reconstruct_path(predecessor, destination):
    path = []
    current = destination
    while current is not None:
        path.append(current)
        current = predecessor[current]
    return path[::-1]

# Example graph with time-dependent edge delays and danger factors
def example_graph():
    # Time-dependent travel time functions
    def travel_time_A_B(t):
        # Example: Travel time from A to B changes over time (linear function)
        if 0 <= t <= 20:
            return 5  # During early hours, travel time is 5 units
        elif 20 < t <= 40:
            return 10  # Congestion causes higher travel time
        else:
            return 7  # Later, the time drops again

    def travel_time_A_C(t):
        # Example: A to C travel time
        if 0 <= t <= 30:
            return 10
        else:
            return 12

    def travel_time_B_C(t):
        # Example: B to C travel time
        return 3  # Fixed travel time

    def travel_time_B_D(t):
        # B to D is time-dependent
        if 0 <= t <= 25:
            return 7
        else:
            return 9

    def travel_time_C_D(t):
        # C to D travel time
        return 4  # Fixed travel time

    # Graph format: node -> {neighbor: (travel_time_function, danger_factor)}
    graph = {
        'A': {'B': (travel_time_A_B, 0.1), 'C': (travel_time_A_C, 0.4)},
        'B': {'C': (travel_time_B_C, 0.2), 'D': (travel_time_B_D, 0.6)},
        'C': {'D': (travel_time_C_D, 0.3)},
        'D': {}
    }
    
    return graph

# Run an example
if __name__ == "__main__":
    graph = example_graph()
    source = 'A'
    destination = 'D'
    T = (0, 60)  # Time interval
    Omega = 0.5  # Safety threshold
    
    path, time = tdssp(graph, None, source, destination, T, Omega)
    
    if path:
        print(f"The shortest safe path from {source} to {destination} is: {path}")
        print(f"Total travel time: {time}")
    else:
        print("No safe path exists within the given danger threshold.")
