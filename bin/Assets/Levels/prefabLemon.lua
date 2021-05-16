prefab = {}
prefab[0] = { Name = "Lemon_"}
prefab[1] = { Component = "Transform", Coord = {X = 0, Y = -300, Z = 0},Rotation = {X=0,Y=0,Z=0},Scale = {X=4,Y=.1,Z=2.3}}
prefab[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Brown", 
				LookAt ={X=1, Y=1, Z=1},
				Visible=true, Shadows=true, RenderingDistance = 9999}
prefab[3] = { Component = "BoxCollider", Type="Box",Width=1000,Height=1,Depth=1000,IsTrigger=false}
prefab[4] = { Component = "RigidBody", Type="Box", Mass=9, Width=40, Depth=40, Height=40, ConstrainAngle = true,Bounciness=1,kinematic=true,IsTrigger=false}
prefab[5] = { Component = "EnemyHealthComponent", Points =5, HitPoints = 5}
