import datetime

def find_palindromes(year):
    
    palindrome_list = []
    
    year_start = year / 1000 * 1000
    year_end   = year / 1000 * 1000 + 101
    
    year_start = year_start if year_start > 1000 else 1000
    year_end   = year_end if year_end < 9999 else 9999
    
    for year in range(year_start, year_end+1):
        
        strYear = '{:4d}'.format(year)
        
        strMonth = strYear[::-1][:2]
        strDay   = strYear[::-1][2:4]
        
        try:
            date = datetime.datetime(int(strYear), int(strMonth), int(strDay))
            strDate = strMonth + strDay + strYear
            palindrome_list.append(strDate)
        except ValueError:
            pass
        
        strMonth = strYear[-1]
        strDay   = strYear[::-1][1:3]
        
        try:
            date = datetime.datetime(int(strYear), int(strMonth), int(strDay))
            strDate = strMonth + strDay + strYear
            palindrome_list.append(strDate)
        except ValueError:
            pass
    
    print(palindrome_list)        
    
    return len(palindrome_list)

if __name__ == "__main__":
    
    print(find_palindromes(1000))
    
