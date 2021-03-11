## SQL 문법 정리.

1. [SELECT](#SELECT)
2. [JOIN](#JOIN)
3. [MAX,MIN,COUNT,SUM](#MAX,MIN,COUNT,SUM)
4. [GROUP BY](#GROUP-BY)

### SELECT

1. 모든 레코드 조회하기
   - 동물 보호에 들어온 모든 동물 정보를 ANIMAL_ID 순으로 조회하는 SQL
   - ORDER BY의 DEFAULT는 ASC(오름차순), 내림차순은 DESC

```sql
SELECT *
FROM ANIMAL_INS
ORDER BY ANIMAL_ID
```

2. 역순 정렬하기
   - 동물 보호소에 들어온 모든 동물의 이름과 보호 시작일을 조회하는 SQL(내림차순)

```sql
SELECT NAME, DATETIME
FROM ANIMAL_INS
ORDER BY ANIMAL_ID DESC
```

3. 아픈 동물 찾기
   - 동물 보호소에 들어온 동물 중 아픈 동물 1의 아이디와 이름을 조회하는 SQL(결과는 ID 순)
   - 조건문 WHERE '조건'

```sql
SELECT ANIMAL_ID,NAME
FROM ANIMAL_INS
WHERE INTAKE_CONDITION = 'Sick'
```

4. 어린 동물 찾기
   - 동물 보호소에 들어온 동물 중 젊은 동물의 아이디와 이름을 조회하는 SQL문(결과는 ID 순)

```sql
SELECT ANIMAL_ID,NAME
FROM ANIMAL_INS
WHERE INTAKE_CONDITION='Aged'
```

5. 동물 아이디와 이름
   - 동물 보호소에 들어온 모든 동물의 아이디와 이름을 ANIMAL_ID순으로 조회하는 SQL

```sql
SELECT ANIMAL_ID,NAME
FROM ANIMAL_INS
ORDER BY ANIMAL_ID
```

6. 여러 기준으로 정렬하기
   - 동물 보호소에 들어온 모든 동물의 아이디와 이름,보호 시작일을 이름 순으로 조회하는 SQL (단, 이름이 같은 동물중에서는 보호를 나중에한 동물을 먼저 보여줘야한다.)
   - ORDER BY 여러 개 예제

```sql
SELECT ANIMAL_ID,NAME,DATETIME
FROM ANIMAL_INS
ORDER BY NAME ASC, DATETIME DESC
```

7. 상위 n개 레코드
   - 동물 보호소에 가장 먼저 들어온 동물의 이름을 조회
   - LIMIT 숫자: 상위 `숫자`만큼의 레코드만 출력

```sql
SELECT NAME
FROM ANIMAL_INS
ORDER BY DATETIME
LIMIT 1
```

### JOIN

1. 없어진 기록 찾기(RIGHT JOIN)
   - 입양을 간 기록은 있는데, 보호소에 들어온 기록이 없는 동물의 ID와 이름을 ID 순으로 조회하는 SQL

```sql
SELECT B.ANIMAL_ID,B.NAME
FROM ANIMAL_INS A
RIGHT JOIN ANIMAL_OUTS B
ON A.ANIMAL_ID = B.ANIMAL_ID
WHERE A.ANIMAL_ID IS NULL
```

2. 있었는데요 없었습니다.(INNER JOIN)
   - 관리자의 실수로 일부 동물의 입양일이 잘못 입력되었다. 보호 시작일보다 입양일이 더 빠른 동물의 아이디와 이름을 조회하는 SQL문 ( 결과는 보호 시작일이 빠른 순으로 조회)

```sql
SELECT B.ANIMAL_ID,B.NAME
FROM ANIMAL_INS A
JOIN ANIMAL_OUTS B
ON B.ANIMAL_ID = A.ANIMAL_ID
WHERE B.DATETIME < A.DATETIME
ORDER BY A.DATETIME
```

3. 오랜 기간 보호한 동물(1) (LEFT JOIN)
   - 아직 입양을 못 간 동물 중, 가장 오래 보호소에 있었던 동물 3마리의 이름과 보호 시작일을 조회하는 SQL (결과는 보호 시작일 순으로 조회)

```sql
SELECT A.NAME,A.DATETIME
FROM ANIMAL_INS A
LEFT JOIN ANIMAL_OUTS B
ON A.ANIMAL_ID = B.ANIMAL_ID
WHERE B.ANIMAL_ID IS NULL
ORDER BY A.DATETIME
LIMIT 3

```

4. 보호소에서 중성화한 동물
   - 보호소에서 중성화 수술을 거친 동물 정보를 알아보려 합니다. 보호소에 들어올 당시에는 중성화되지 않았지만, 보호소를 나갈 당시에는 중성화된 동물의 아이디와 생물 종, 이름을 조회하는 아이디 순으로 조회하는 SQL

```sql
SELECT B.ANIMAL_ID,B.ANIMAL_TYPE,B.NAME
FROM ANIMAL_INS A
JOIN ANIMAL_OUTS B
ON A.ANIMAL_ID = B.ANIMAL_ID
WHERE A.SEX_UPON_INTAKE != B.SEX_UPON_OUTCOME
```

5. 우유와 요거트가 담긴 장바구니
   - 데이터 분석 팀에서는 우유와 요거트를 동시에 구입한 장바구니가 있는지 알아보려 합니다. 우유와 요거트를 동시에 구입한 장바구니의 아이디를 조회하는 SQL. (결과는 장바구니의 아이디 순으로 나와야 합니다.)

```sql
SELECT P.CART_ID
FROM CART_PRODUCTS P
JOIN (SELECT CART_ID FROM CART_PRODUCTS WHERE NAME="요거트") YO
ON P.CART_ID=YO.CART_ID
WHERE NAME="우유"
ORDER BY P.CART_ID
```

- JOIN: 일반적으로 INNER JOIN
- LEFT JOIN: 왼쪽 TABLE을 기준으로 JOIN
  - `오른쪽 테이블 ID IS NULL` 을 하게되면 왼쪽 테이블의 정보만 나온다.
- RIGHT JOIN: 오른쪽 TABLE을 기준으로 JOIN
  - `왼쪽 테이블 ID IS NULL`을 하게되면 오른쪽 테이블의 정보만 나온다.

<img src="https://blog.kakaocdn.net/dn/bVqyCr/btqBlijYkN3/RZMFMrhcZZJI7iGu1AXdKK/img.png"><br>

<br>

### MAX,MIN,COUNT,SUM

1.  최댓값 구하기
    - 가장 최근에 들어온 동물은 언제 들어왔는지 조회하는 SQL

```sql
SELECT MAX(DATETIME)
FROM ANIMAL_INS
```

2.  최솟값 구하기
    - 가장 먼저 들어온 동물은 언제 들어왔는지 조회하는 SQL

```sql
SELECT MIN(DATETIME)
FROM ANIMAL_INS
```

3.  동물 수 구하기
    - 동물 보호소에 동물이 몇 마리 들어왔는지 조회하는 SQL

```sql
SELECT COUNT(ANIMAL_ID) count
FROM ANIMAL_INS
```

4.  중복 제거하기
    - 동물 보호소에 들어온 동물의 이름은 몇 개인지 조회하는 SQL (이름이 NULL인 경우 집계하지 않으며 중복 이름은 하나로)

```sql
SELECT COUNT(A.NAME) count
FROM (SELECT NAME FROM ANIMAL_INS GROUP BY NAME) AS A
WHERE NAME IS NOT NULL
```

### GROUP BY

1. 고양이와 개는 몇 마리 있을까
   - 동물 보호소에 들어온 동물 중 고양이와 개가 각각 몇마리인지 조회하는 SQL(고양이를 개 먼저 조회)

```sql
SELECT ANIMAL_TYPE, COUNT(*) AS count
FROM ANIMAL_INS
WHERE ANIMAL_TYPE = 'Cat' OR ANIMAL_TYPE = 'Dog'
GROUP BY ANIMAL_TYPE
ORDER BY ANIMAL_TYPE
```

2. 동명 동물 수 찾기
   - 동물 보호소에 들어온 동물 이름 중 두 번 이상 쓰인 이름과 해당 이름이 쓰인 횟수를 조회하는 SQL (이름 없는 동물은 제외, 결과는 이름 순)

```sql
SELECT NAME, COUNT(*) AS count
FROM ANIMAL_INS
WHERE NAME IS NOT NULL
GROUP BY NAME
HAVING count > 1
ORDER BY NAME
```

3. 입양 시각 구하기(1)
   - 보호소에서는 몇 시에 입양이 가장 활발하게 일어나는지 알아보려 합니다. 09::00부터 19:59까지, 각 시간대 별로 입양이 몇 건이나 발생했는지 조회하는 SQL문을 작성(결과는 시간대 순으로 정렬)

```sql
SELECT HOUR(DATETIME), COUNT(*) AS count
FROM ANIMAL_OUTS
WHERE HOUR(DATETIME) >=9  AND HOUR(DATETIME) < 20
GROUP BY HOUR(DATETIME)
ORDER BY HOUR(DATETIME)
```

4. 입양 시각 구하기(2)
   - 보호소에서는 몇 시에 입양이 가장 활발하게 일어나는지 알아보려 합니다. 0시부터 23시까지, 각 시간대별로 입양이 몇 건이나 발생했는지 조회하는 SQL문을 작성 (결과는 시간대 순으로 정렬)

```sql
SET @HOUR = -1; SELECT (@HOUR := @HOUR +1) AS HOUR, (SELECT COUNT(*) FROM ANIMAL_OUTS WHERE HOUR(DATETIME) = @HOUR) AS COUNT FROM ANIMAL_OUTS WHERE @HOUR < 23
```

- HAVING: 집계함수(SUM,COUNT,....)를 가지고 조건 비교시 사용.
  - GROUP BY 절과 함께 사용.
- DATETIME: HOUR, MINUTE, SECOND와 같이 사용 가능.
