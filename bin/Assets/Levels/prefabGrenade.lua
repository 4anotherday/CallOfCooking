prefab={}
prefab[0] ={Name ="Grenade_"}
prefab[1]={ Component = "Transform", Coord = {X = 150, Y = -290, Z = 100},Rotation = {X=0,Y=0,Z=0},Scale = {X=0.3,Y=0.3,Z=0.3}}
prefab[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Orange", 
			RotateAngle = 0, Rotate={X=0, Y=0, Z=0}, Scale = {X=0, Y=0, Z=0}, LookAt ={X=1, Y=1, Z=1},
			Visible=true, Shadows=true, RenderingDistance = 1000}
prefab[3] = { Component = "RigidBody", Type="Box", Mass=9, Width=40, Depth=40, Height=40, ConstrainAngle = true,Bounciness=1,kinematic=true,IsTrigger=false}
prefab[4] = { Component = "EnemyHealthComponent", Points =5, HitPoints = 5}
prefab[5] = { Component = "GrenadeBehaviorComponent", Range =100, MovementSpeed = 1, AttackSpeed=2}

