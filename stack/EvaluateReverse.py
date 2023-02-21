class Solution:
    
    def evalRPN(self, tokens: list[str]) -> int:
        #add each element to stack, 
        funcMap = {
            "/":lambda a,b: int((int(a)/int(b))),
            "*":lambda a,b: int(a)*int(b),
            "+":lambda a,b: int(a)+int(b),
            "-":lambda a,b: int(a)-int(b)
        }
        def eval(l):
            command = l[-1]
            a = l[0]
            b = l[1]
            return funcMap[command](a,b)

        stack = []
        for token in tokens:
            stack.append(token)
            if token in funcMap:
                ev = eval(stack[-3:])
                stack = stack[:-3]
                stack.append(ev)
                
        return stack[0]
    

def main():
    s = Solution()
    tok = ["2","1","+","3","*"]
    print(s.evalRPN(tok))
    
if __name__ == "__main__":
    main()
        

