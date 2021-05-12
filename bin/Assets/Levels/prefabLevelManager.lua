-- prefab[1] = ROUND1 CONFIG, prefab[2] = ROUND2 CONFIG... prefab[N] = ROUNDN CONFIG
prefab={}
prefab[0] = { HowManyRespawnPositions = 3, RespawnPositions = {{X=10,Y=10,Z=10},{X=20,Y=20,Z=20},{X=30,Y=30,Z=30}}}
prefab[1] = { TotalEnemies = 30, WaveTime = 5,
			  Granade    = { HowMany = 5, RespawnTime = 2}, 
			  Lemon      = { HowMany = 10, RespawnTime = 2}, 
			  Watermelon = { HowMany = 15, RespawnTime = 2}} 
prefab[2] = { TotalEnemies = 45, WaveTime = 3,
			  Granade    = { HowMany = 10, RespawnTime = 1}, 
			  Lemon      = { HowMany = 15, RespawnTime = 1}, 
			  Watermelon = { HowMany = 20, RespawnTime = 1}} 