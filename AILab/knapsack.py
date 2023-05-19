class Item:
    def __init__(self,weight,value):
        self.weight = weight
        self.value = value

def greedyFractionalKnapsack(items,capacity):
    items.sort(key=lambda item: (item.value/item.weight), reverse=True) 
    finalvalue = 0.0
    remaining_capacity = capacity
    for item in items:
        if item.weight <= remaining_capacity:
            remaining_capacity -= item.weight
            finalvalue += item.value
        else:
            finalvalue += item.value * remaining_capacity / item.weight
            break
    return finalvalue

def recursiveKnapsackHelper(items, remaining_capacity):
    if items[0].weight<=remaining_capacity:
        remaining_capacity -= items[0].weight
        return items[0].value + recursiveKnapsackHelper(items[1:], remaining_capacity)
    return items[0].value * remaining_capacity / items[0].weight

def recursiveKnapsack(items,capacity):
        items.sort(key=lambda item: (item.value/item.weight), reverse=True)
        return recursiveKnapsackHelper(items,capacity)
 
 
if __name__ == "__main__":
    no_of_items = 5
    weights=[5,10,15,22,25]
    values=[30,40,45,77,90]
    items = []
    for i in range(no_of_items):
        items.append(Item(weights[i], values[i]))
    capacity = 60

    max_profit = greedyFractionalKnapsack(items,capacity)
    max_profit2 = recursiveKnapsack(items,capacity)
    print(f"Maximum Profit: {max_profit}")
    print(f"Maximum Profit using Recursion: {max_profit2}")