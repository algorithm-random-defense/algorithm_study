--연도 별 평균 미세먼지 농도 조회하기
SELECT YEAR(YM) YEAR, ROUND(AVG(PM_VAL1), 2) 'PM10', ROUND(AVG(PM_VAL2), 2) 'PM2.5'
FROM AIR_POLLUTION
WHERE LOCATION2 = '수원'
GROUP BY YEAR
ORDER BY YEAR ASC;