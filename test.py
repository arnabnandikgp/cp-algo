def balbichi(num):
    global result
    if(num%2==0):
        if(num%10==0):
            result='zero'
        else:
            result='even'
    else:
        if(num%10==5):
            result='five'
        else:
            result='odd'
    return result       
print(balbichi(10))
