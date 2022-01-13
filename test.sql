select assists,
        turnovers,
       CAST( CAST(assists AS FLOAT)  / turnovers AS DECIMAL(10,6)) AS assist_turnover_ratio
FROM career_summaries;