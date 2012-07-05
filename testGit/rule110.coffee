applyRule = (arr) ->
        for i in [0..(arr.length-1)]
                if (i-1 < 0)
                        x = arr[arr.length-1]
                else
                        x = arr[i-1]
                y = arr[i]
                if (i+1 == arr.length)
                        z = arr[0]
                else
                        z = arr[i+1]
                        
                if (x == 1 and y == 1 and z == 1) or (x == 1 and y == 0 and z == 0) or (x == 0 and y == 0 and z == 0)
                        
                        arr[i] = 0
                else
                        
                        arr[i] = 1
        return arr

myArr = [0, 0, 1, 1, 1, 0, 0]
console.log (myArr)
console.log (applyRule(myArr))
