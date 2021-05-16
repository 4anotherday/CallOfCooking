-- prefab[1] = ROUND1 CONFIG, prefab[2] = ROUND2 CONFIG... prefab[N] = ROUNDN CONFIG
prefab={}
prefab[0] = { HowManyRespawnPositions = 1, RespawnPositions = {{X=0,Y=0.5,Z=2}, {X=-2,Y=0.5,Z=0}}}
prefab[1] = { TotalEnemies = 30, WaveTime = 5,
			  Granade    = { HowMany = 5, RespawnTime = 2}, 
			  Lemon      = { HowMany = 10, RespawnTime = 2}, 
			  Watermelon = { HowMany = 15, RespawnTime = 2}} 
prefab[2] = { TotalEnemies = 45, WaveTime = 3,
			  Granade    = { HowMany = 10, RespawnTime = 1}, 
			  Lemon      = { HowMany = 15, RespawnTime = 1}, 
			  Watermelon = { HowMany = 20, RespawnTime = 1}} 