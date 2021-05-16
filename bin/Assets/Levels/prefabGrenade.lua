prefab={}
prefab[0] ={Name ="Grenade_"}
prefab[1]={ Component = "Transform", Coord = {X = 0.1, Y = 1, Z = 0},Rotation = {X=0,Y=0,Z=0},Scale = {X=0.3,Y=0.3,Z=0.3}}
prefab[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Orange", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
prefab[3] = { Component = "RigidBody", Type="Box", Mass=9, Width=1, Depth=1, Height=1, ConstrainAngle = true,Bounciness=1, kinematic=false,IsTrigger=false}
prefab[4] = { Component = "EnemyHealthComponent", Points =5, HitPoints = 5}
prefab[5] = { Component = "GrenadeBehaviorComponent", Range =100, MovementSpeed = 1, AttackSpeed=2}

