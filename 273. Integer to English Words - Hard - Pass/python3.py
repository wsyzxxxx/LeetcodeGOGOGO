singleMap = {
    1: "One", 2: "Two", 3: "Three", 4: "Four", 5: "Five", 6: "Six", 7: "Seven", 8: "Eight", 9: "Nine"
}
tenthMap = {
    10: "Ten", 11: "Eleven", 12: "Twelve", 13: "Thirteen", 14: "Fourteen", 15: "Fifteen",
    16: "Sixteen", 17: "Seventeen", 18: "Eighteen", 19: "Nineteen",
    20: "Twenty", 30: "Thirty", 40: "Forty", 50: "Fifty", 60: "Sixty", 70: "Seventy",
    80: "Eighty", 90: "Ninety"
}
newMap = {
    1000: "Thousand", 1000000: "Million", 1000000000: "Billion"
}

class Solution:
    def numberToWords(self, num: int) -> str:
        if (num == 0):
            return "Zero"
        
        res = ""
        limits = 1000000000
        while limits > 0 and num > 0:
            if (num < limits):
                limits //= 1000
                continue
            tmpNum = num
            tmpNum //= limits
            limit = 100
            
            if (tmpNum >= 100):
                res += singleMap[tmpNum // 100] + " Hundred "
                tmpNum = tmpNum % 100
            if tmpNum in tenthMap:
                res += tenthMap[tmpNum] + " "
            elif tmpNum // 10 * 10 in tenthMap:
                res += tenthMap[tmpNum // 10 * 10] + " "
                tmpNum %= 10
            if tmpNum in singleMap:
                res += singleMap[tmpNum] + " "
                
            if limits > 1:
                res += newMap[limits] + " "
                num %= limits
            limits //= 1000
            
        return res[:-1]