# 정리
# 0. 리스트 인덱스 이해
# 1. commands 리스트 구조 이해
# 2. 자르기 --> slice
# 3. 정렬하기 --> sort 
# 4. 수 찾기 --> index

def solution(array, commands):
    answer = []
    # 0. 리스트 인덱스 이해
    # 리스트의 인덱스는 항상 0부터 시작
    
    # 1. commands 리스트 구조 이해
    # for문을 사용하여 commands 리스트에 있는 또 다른 list를 'command'라는 변수에 담기 
    # command[0] = i, command[1] = j, command[2] = k
    for command in commands:
        # 2. 자르기
        # slice란: list의 일부분을 잘라서 가져온다는 의미로, 
        # ex. array[1:5]는 1번째 인덱스부터 '5-1'번째까지 자른다.
        array2 = array[command[0]-1:command[1]]
        
        # 3. 정렬하기
        array2.sort()
        
        # 4. 수 찾기
        answer.append(array2[command[2]-1])
        
    return answer


print(solution([1, 5, 2, 6, 3, 7, 4], [[2, 5, 3], [4, 4, 1], [1, 7, 3]]))
