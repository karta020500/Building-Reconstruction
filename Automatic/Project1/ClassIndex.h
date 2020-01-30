class KmlFileXYZ{
public:
	int Id;
	double x;
	double y;
	double z;
	int Qflag;
	int count;
	int FId;
};

class XYZarraytemp{
public:
	char  xyz[8192];

};



class BPCReport{
public:
	double x1, y1, x2, y2, z1, z2;
	double d1, d2, d3;
	char Tilename[128];
};


class BpcTilename{
public:
	char Tilename[128];
};
class BpcTilenameTemp{
public:
	int Qflag;
	int num;
	char Tilename[4][128];
};


class PointA
{
public:
	double x;
	double y;
	double z;
};

class BPC2XYZI{
public:
	double x, y, z, i;
};

class GetID{
public:
	int NO;
	char name[128];
};

class KMLcount{
public:
	int id;
	int count;
};

class Grdinn{
public:
	int i;
	int Fid;
	char  xyz[8192];

};



class GetGrd{
public:
	double x;
	double y;
	double z;
	int id;
	int M;
};


class GetLidra{
public:
	double x;
	double y;
	double z;
	double v;
	int id;
	int M;
};


class LidraXYZX{
public:
	double xLup;
	double yLup;
	double xRdown;
	double yRdown;
	char name[128];
};

class PointXYZa{
public:
	double x;
	double y;
	double z;

};

class PointToTran{
public:
	double x1,y1,z1;
	double x2, y2, z2;
	double x3, y3, z3;
	double qx, qy, qz;
	int M;
	int id;
	
};