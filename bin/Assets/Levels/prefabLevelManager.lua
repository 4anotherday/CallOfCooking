-- prefab[1] = ROUND1 CONFIG, prefab[2] = ROUND2 CONFIG... prefab[N] = ROUNDN CONFIG
prefab={}
prefab[0] = { HowManyRespawnPositions = 3, RespawnPositions = {{X=2,Y=0.5,Z=2}, {X=-2,Y=0.5,Z=0}, {X=2,Y=0.5,Z=-2}}}
prefab[1] = { TotalEnemies = 1, WaveTime = 3,
			  Granade    = { HowMany = 1, RespawnTime = 2}, 
			  Lemon      = { HowMany = 0, RespawnTime = 2}, 
			  Watermelon = { HowMany = 0, RespawnTime = 2}} 
prefab[2] = { TotalEnemies = 1, WaveTime = 10,
			  Granade    = { HowMany = 0, RespawnTime = 1}, 
			  Lemon      = { HowMany = 0, RespawnTime = 1}, 
			  Watermelon = { HowMany = 1, RespawnTime = 1}} 