prefab={}
prefab[0] = { Name ="GrenadeBullet_"}
prefab[1]=  { Component = "Transform", Coord = {X = 0, Y = 0, Z = 0},Rotation = {X=0,Y=0,Z=0},Scale = {X=.1,Y=.1,Z=.1}}
prefab[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Fucsia", 
				Visible=true, Shadows=true, RenderingDistance = 1000}
prefab[3] = { Component = "RigidBody", Type="Box", Mass=30, Width=1, Depth=1, Height=1, ConstrainAngle = true, Bounciness=0,kinematic=false, IsTrigger=true}
prefab[4] = { Component = "GrenadeBulletBehaviorComponent",Damage=5, MovementSpeed = 20, LifeTime= 5.0}
