#include<bits/stdc++.h>

class UserMainCode(object):
    @classmethod
    def calculateSum(cls, input1, input2):
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        n = input1
        arr = input2

        max_elem = max(arr)
        gcd_dict = {}  # Store calculated GCDs in a dictionary

        for i in range(n):
            if arr[i] in gcd_dict:
                arr[i] = gcd_dict[arr[i]]
            else:
                arr[i] = gcd(arr[i], max_elem)
                gcd_dict[arr[i]] = arr[i]  # Store calculated GCD in dictionary

        arr.sort()

        left, right = 0, n - 1
        result = []

        while left < right:
            result.append(gcd(arr[left], arr[right]))
            left += 1
            right -= 1

        return sum(result)