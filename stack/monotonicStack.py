from collections import deque

def dailyTemperatures(temperatures: list[int]) -> list[int]:
    results = [0]*(len(temperatures))

    stack = [0]
    for i in range(1,len(temperatures)):
        curTemp = temperatures[i]
        topOfStackTemp = temperatures[stack[-1]]
        if (curTemp <= topOfStackTemp):
            stack.append(i)
        else:
            while stack and temperatures[stack[-1]] < curTemp:
                index = stack.pop()
                results[index] = i - index

            stack.append(i)

    return results





print(dailyTemperatures([73,74,75,71,69,72,76,73]))