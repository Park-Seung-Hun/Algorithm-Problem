## SQL 문법 정리.

1. [SELECT](#SELECT)
2. [JOIN](#JOIN)
3. [SUM,MAX,MIB](#SUM,MAX,MIN)

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

1. 없어진 기록 찾기
   - 입양을 간 기록은 있는데, 보호소에 들어온 기록이 없는 동물의 ID와 이름을 ID 순으로 조회하는 SQL

```sql
FROM B.ANIMAL_ID,B.NAME
FROM ANIMAL_INS A
RIGHT JOIN ANIMAL_OUTS B
ON A.ANIMAL_ID = B.ANIMAL_ID
WHERE A.ANIMAL_ID IS NULL
```

1. 있었는데요 없었습니다.
   - ㄴ

```sql

```

3. 오랜 기간 보호한 동물(1)
   - ㄴ

```sql

```

4. 보호소에서 중성화한 동물
   - ㄴ

```sql

```

5. 우유와 요거트가 담긴 장바구니
   - ㄴ

```sql

```
