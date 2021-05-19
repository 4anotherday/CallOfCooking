prefab={}
prefab[0] ={Name ="Grenade_"}
prefab[1]={ Component = "Transform", Coord = {X = 0, Y = 0, Z = 0},Rotation = {X=0,Y=0,Z=0},Scale = {X=0.3,Y=0.3,Z=0.3}}
prefab[2] = {	Component = "RenderObject", MeshName="granada.mesh", Material="Granada", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
prefab[3] = { Component = "RigidBody", Type="Box", Mass=1,ConstrainAngle = true,Bounciness=1, Kinematic=true}
prefab[4] = { Component = "EnemyHealthComponent", Points =1, HitPoints = 1}
prefab[5] = { Component = "GrenadeBehaviorComponent", Range =2.5, MovementSpeed = 1, AttackSpeed=2}

