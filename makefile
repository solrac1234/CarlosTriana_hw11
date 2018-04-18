vel.png pos.png phase.png:tray.txt
	
python CT_graph.py
		
CT_gravity.py:
	
g++ CT_gravity.cpp -o CT_gravity.x
	
tray.txt:DG_gravity.x
	
./CT_gravity.x > tray.txt
		

	



	
	


