prefab = {}
prefab[0] = { Name = "Watermelon_"}
prefab[1] = { Component = "Transform", Coord = {X = 0, Y = -500, Z = -300},Rotation = {X=0,Y=0,Z=0},Scale = {X=0.3,Y=0.3,Z=0.4}}
prefab[2] = { Component = "RenderObject", MeshName="sandia.mesh", Material="sandia", 
				LookAt ={X=1, Y=1, Z=1},
				Visible=true, Shadows=true, RenderingDistance = 9999}
prefab[3] = { Component = "RigidBody", Type="Box", Mass=1,ConstrainAngle = true,Bounciness=1,Kinematic=true}
prefab[4] = { Component = "EnemyHealthComponent", Points = 5, HitPoints = 5}
prefab[5] = { Component = "WatermelonBehaviorComponent", Range =1, MovementSpeed = 1, TimeToExplode= 2,Damage=1}
