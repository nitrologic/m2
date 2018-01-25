' gis stuff

' some code derived from http://www.linz.govt.nz/geodetic/software-downloads


Alias Degrees:Double
Alias Meters:Double

Struct LatLon
	Field lat:Degrees
	Field lon:Degrees
End

Const RadiansPerDegree:=math.Pi/180.0

Function HaversineDistance:Meters(p0:LatLon,p1:LatLon)
	Const R:=6371000000.0
	Local dlat2:=0.5*(p1.lat-p0.lat)*RadiansPerDegree
	Local dlon2:=0.5*(p1.lon-p0.lon)*RadiansPerDegree
	If dlat2=0 And dlon2=0 Return 0	
	Local a:= Sin(dlat2)*Sin(dlat2)+Cos(p1.lat*RadiansPerDegree)*Cos(p2.lat*RadiansPerDegree)*Sin(dlon2)*Sin(dlon2)
	Local c:=2*ATan2(Sqrt(a),Sqrt(1-a))
	Local d:=R*c
	Return d
End

Class NZTM
	' Define the parameters for the International Ellipsoid used for the NZGD2000 datum (and hence for NZTM)
	
	Const NZTM_A:=6378137
	Const NZTM_RF:=298.257222101

	Const NZTM_CM:=173.0 
	Const NZTM_OLAT:=0.0 
	const NZTM_SF:=0.9996
	
	Const NZTM_FE:=1600000.0
	Const NZTM_FN:=10000000.0
	
	' Routines to convert NZTM to latitude and longitude and vice versa.
	' Northing (n) and Easting (e) are in metres
	' Latitude (lt) and Longitude (ln) are in radians
	
End

Function Main()
	Print "hello"
End


#rem


	final static double rad2deg = 180.0/Math.PI ;	
	
	/* Define the parameters for the International Ellipsoid
		used for the NZGD2000 datum (and hence for NZTM) */

	final static double NZTM_A=6378137;
	final static double NZTM_RF=298.257222101;

	final static double NZTM_CM=173.0; 
	final static double NZTM_OLAT=0.0; 
	final static double NZTM_SF=0.9996; 

	final static double NZTM_FE=1600000.0; 
	final static double NZTM_FN=10000000.0;
	
//	final static double NZTM_FE=2510000.0; 
//	final static double NZTM_FN=6023150.0;
	

//	void nztm_geod( double n, double e, double *lt, double *ln );
//	void geod_nztm( double lt, double ln, double *n, double *e );

	static class TMProjection {
		double meridian;		/* Central meridian */
		double scalef;			/* Scale factor */
		double orglat;			/* Origin latitude */
		double falsee;			/* False easting */
		double falsen;			/* False northing */
		double utom;			/* Unit to metre conversion */

		double a, rf, f, e2, ep2;	/* Ellipsoid parameters */
		double om;				/* Intermediate calculation */
	}

//	static double meridian_arc( tmprojection *tm, double lt );

/* Initiallize the TM structure	*/

static void define_tmprojection( TMProjection tm, double a, double rf, double cm, double sf, double lto, double fe, double fn, double utom ) {
	
		double f;
	
		tm.meridian = cm;
		tm.scalef = sf;
		tm.orglat = lto;
		tm.falsee = fe;
		tm.falsen = fn;
		tm.utom = utom;
		if( rf != 0.0 ) f = 1.0/rf; else f = 0.0;
		tm.a = a;
		tm.rf = rf;
		tm.f = f;
		tm.e2 = 2.0*f - f*f;
		tm.ep2 = tm.e2/( 1.0 - tm.e2 );
	
		tm.om = meridian_arc( tm, tm.orglat );
	}


/***************************************************************************/
/*																		*/
/*	meridian_arc															*/
/*																		*/
/*	Returns the length of meridional arc (Helmert formula)				*/
/*	Method based on Redfearn's formulation as expressed in GDA technical	*/
/*	manual at http://www.anzlic.org.au/icsm/gdatm/index.html				*/
/*																		*/
/*	Parameters are														*/
/*	projection															*/
/*	latitude (radians)													*/
/*																		*/
/*	Return value is the arc length in metres								*/
/*																		*/
/***************************************************************************/


static double meridian_arc( TMProjection tm, double lt ) {
	double e2 = tm.e2;
	double a = tm.a;
	double e4;
	double e6;
	double A0;
	double A2;
	double A4;
	double A6;

	e4 = e2*e2;
	e6 = e4*e2;
 
	A0 = 1 - (e2/4.0) - (3.0*e4/64.0) - (5.0*e6/256.0);
	A2 = (3.0/8.0) * (e2+e4/4.0+15.0*e6/128.0);
	A4 = (15.0/256.0) * (e4 + 3.0*e6/4.0);
	A6 = 35.0*e6/3072.0;

	return	a*(A0*lt-A2*Math.sin(2*lt)+A4*Math.sin(4*lt)-A6*Math.sin(6*lt));
}

/*************************************************************************/
/*																		*/
/*	foot_point_lat														*/
/*																		*/
/*	Calculates the foot point latitude from the meridional arc			*/
/*	Method based on Redfearn's formulation as expressed in GDA technical*/
/*	manual at http://www.anzlic.org.au/icsm/gdatm/index.html			*/
/*																		*/
/*	Takes parameters													*/
/*		tm definition (for scale factor)								*/
/*		meridional arc (metres)											*/
/*																		*/
/*	Returns the foot point latitude (radians)							*/ /*																		*/
/*************************************************************************/


static double foot_point_lat( TMProjection tm, double m ) {
	double f = tm.f;
	double a = tm.a;
	double n;
	double n2;
	double n3;
	double n4;
	double g;
	double sig;
	double phio;
 
	n	= f/(2.0-f);
	n2 = n*n;
	n3 = n2*n;
	n4 = n2*n2;
 
	g = a*(1.0-n)*(1.0-n2)*(1+9.0*n2/4.0+225.0*n4/64.0);
	sig = m/g;
 
	phio = sig + (3.0*n/2.0 - 27.0*n3/32.0)*Math.sin(2.0*sig)
					+ (21.0*n2/16.0 - 55.0*n4/32.0)*Math.sin(4.0*sig)
					+ (151.0*n3/96.0) * Math.sin(6.0*sig)
					+ (1097.0*n4/512.0) * Math.sin(8.0*sig);
 
	return phio;
	}





/***************************************************************************/
/*																		*/
/*	tmgeod																*/
/*																		*/
/*	Routine to convert from Tranverse Mercator to latitude and longitude. */
/*	Method based on Redfearn's formulation as expressed in GDA technical	*/
/*	manual at http://www.anzlic.org.au/icsm/gdatm/index.html				*/
/*																		*/
/*	Takes parameters														*/
/*		input easting (metres)											*/
/*		input northing (metres)											*/
/*		output latitude (radians)											*/
/*		output longitude (radians)										*/
/*																		*/
/***************************************************************************/

static void tm_geod( TMProjection tm,double ce, double cn, double ltln[] ) {
	double fn = tm.falsen;
	double fe = tm.falsee;
	double sf = tm.scalef;
	double e2 = tm.e2;
	double a = tm.a;
	double cm = tm.meridian;
	double om = tm.om;
	double utom = tm.utom;
	double cn1;
	double fphi;
	double slt;
	double clt;
	double eslt;
	double eta;
	double rho;
	double psi;
	double E;
	double x;
	double x2;
	double t;
	double t2;
	double t4;
	double trm1;
	double trm2;
	double trm3;
	double trm4;
 
	cn1	=	(cn - fn)*utom/sf + om;
	fphi = foot_point_lat(tm, cn1);
	slt = Math.sin(fphi);
	clt = Math.cos(fphi);
 
	eslt = (1.0-e2*slt*slt);
	eta = a/Math.sqrt(eslt);
	rho = eta * (1.0-e2) / eslt;
	psi = eta/rho;
 
	E = (ce-fe)*utom;
	x = E/(eta*sf);
	x2 = x*x;
 
 
	t = slt/clt;
	t2 = t*t;
	t4 = t2*t2;
 
	trm1 = 1.0/2.0;
 
	trm2 = ((-4.0*psi
				+9.0*(1-t2))*psi
				+12.0*t2)/24.0;
 
	trm3 = ((((8.0*(11.0-24.0*t2)*psi
					-12.0*(21.0-71.0*t2))*psi
					+15.0*((15.0*t2-98.0)*t2+15))*psi
					+180.0*((-3.0*t2+5.0)*t2))*psi + 360.0*t4)/720.0;
 
	trm4 = (((1575.0*t2+4095.0)*t2+3633.0)*t2+1385.0)/40320.0;
 
	ltln[0] = fphi+(t*x*E/(sf*rho))*(((trm4*x2-trm3)*x2+trm2)*x2-trm1);
 
	trm1 = 1.0;
 
	trm2 = (psi+2.0*t2)/6.0;
 
	trm3 = (((-4.0*(1.0-6.0*t2)*psi
				+(9.0-68.0*t2))*psi
				+72.0*t2)*psi
				+24.0*t4)/120.0;
 
	trm4 = (((720.0*t2+1320.0)*t2+662.0)*t2+61.0)/5040.0;
 
	ltln[1] = cm - (x/clt)*(((trm4*x2-trm3)*x2+trm2)*x2-trm1);
}


/****************************************************************************/
/*																			*/
/*	geodtm																	*/
/*																			*/
/*	Routine to convert from latitude and longitude to Transverse Mercator.	*/
/*	Method based on Redfearn's formulation as expressed in GDA technical	*/
/*	manual at http://www.anzlic.org.au/icsm/gdatm/index.html				*/
/*	Loosely based on FORTRAN source code by J.Hannah and A.Broadhurst.		*/
/*																			*/
/*	Takes parameters														*/
/*		input latitude (radians)											*/
/*		input longitude (radians)											*/
/*		output easting	(metres)											*/
/*		output northing (metres)											*/
/*																			*/
/****************************************************************************/


static void geod_tm( TMProjection tm, double ln, double lt, double ne[]) {
	double fn = tm.falsen;
	double fe = tm.falsee;
	double sf = tm.scalef;
	double e2 = tm.e2;
	double a = tm.a;
	double cm = tm.meridian;
	double om = tm.om;
	double utom = tm.utom;
	double dlon;
	double m;
	double slt;
	double eslt;
	double eta;
	double rho;
	double psi;
	double clt;
	double w;
	double wc;
	double wc2;
	double t;
	double t2;
	double t4;
	double t6;
	double trm1;
	double trm2;
	double trm3;
	double gce;
	double trm4;
	double gcn;
 
	dlon	=	ln - cm;
	while ( dlon > Math.PI ) dlon -= Math.PI*2;
	while ( dlon < -Math.PI ) dlon += Math.PI*2;
 
	m = meridian_arc(tm,lt);
 
	slt = Math.sin(lt);
 
	eslt = (1.0-e2*slt*slt);
	eta = a/Math.sqrt(eslt);
	rho = eta * (1.0-e2) / eslt;
	psi = eta/rho;
 
	clt = Math.cos(lt);
	w = dlon;
 
	wc = clt*w;
	wc2 = wc*wc;
 
	t = slt/clt;
	t2 = t*t;
	t4 = t2*t2;
	t6 = t2*t4;
 
	trm1 = (psi-t2)/6.0;
 
	trm2 = (((4.0*(1.0-6.0*t2)*psi 
					+ (1.0+8.0*t2))*psi 
					- 2.0*t2)*psi+t4)/120.0;
 
	trm3 = (61 - 479.0*t2 + 179.0*t4 - t6)/5040.0;
 
	gce = (sf*eta*dlon*clt)*(((trm3*wc2+trm2)*wc2+trm1)*wc2+1.0);
	ne[1] = gce/utom+fe;
 
	trm1 = 1.0/2.0;
 
	trm2 = ((4.0*psi+1)*psi-t2)/24.0;
 
	trm3 = ((((8.0*(11.0-24.0*t2)*psi
				-28.0*(1.0-6.0*t2))*psi
				+(1.0-32.0*t2))*psi 
				-2.0*t2)*psi
				+t4)/720.0;
 
	trm4 = (1385.0-3111.0*t2+543.0*t4-t6)/40320.0;
 
	gcn = (eta*t)*((((trm4*wc2+trm3)*wc2+trm2)*wc2+trm1)*wc2);
	ne[0] = (gcn+m-om)*sf/utom+fn;

	return;
	}

/* Define a static implementation of tmprojection */
/* Note: for some implementations it may be better to create this
	dynamically and develop modified versions of the transformation
	functions to take this as a parameter */

	static TMProjection nztm_projection;
	static boolean initiallized = false;

	static TMProjection get_nztm_projection(){
		if( ! initiallized ){
			nztm_projection=new TMProjection();
			define_tmprojection( nztm_projection, NZTM_A, NZTM_RF,
				NZTM_CM/rad2deg, NZTM_SF, NZTM_OLAT/rad2deg, NZTM_FE, NZTM_FN,
				1.0);
			initiallized = true;
		}
		return nztm_projection;
	}

/* Functions implementation the TM projection specifically for the
	NZTM coordinate system
*/

	static void nztm_geod( double n, double e, double latlon[] ){
		TMProjection nztm = get_nztm_projection();
		tm_geod( nztm, e, n, latlon );
		latlon[0]*=rad2deg;
		latlon[1]*=rad2deg;
	}
	
	static void geod_nztm( double lt, double ln, double ne[] ){
		TMProjection nztm = get_nztm_projection();
		geod_tm( nztm, ln, lt, ne );
	}
	// n = 5920054 e=1756430
	static String test_nztm(){
		
		StringBuffer sb=new StringBuffer();
		
		double d[]=new double[2];
		
		double lat=-36.852490;
		double lon=174.754652;
		
		geod_nztm(lat/rad2deg,lon/rad2deg,d);
				
		sb.append("North="+d[0]+" East="+d[1]+"\t");
		
		nztm_geod(d[0],d[1],d);

		sb.append("Lat="+d[0]+" Lon="+d[1]+"\n");
		
		return sb.toString();
	}
	

/*
int mayne( int argc, char *argv[] ) {
	double e, n, lt, ln, e1, n1;
	while(1) {
	printf("Enter NZTM easting, northing: ");
	if( scanf("%lf%lf",&e,&n) != 2 ) break;
	nztm_geod( n, e, &lt, &ln );
	geod_nztm( lt, ln, &n1, &e1 );
	printf("\nInput NZTM e,n:	%12.3lf %12.3lf\n",e,n);
	printf("Output Lat/Long: %12.6lf %12.6lf\n",lt*rad2deg,ln*rad2deg);
	printf("Output NZTM e,n: %12.3lf %12.3lf\n",e1,n1);
	printf("Difference:		%12.3lf %12.3lf\n\n",e1-e,n1-n);
	}
	return 0;
	}	
*/
}




/***********************************************************************
*
*  $Id: linzgrid.c,v 1.2 2001/05/23 00:09:16 ccrook Exp $
*
*  Description:
*
*  This module implements grid based transformation of 
*  latitude/longitude coordinates using an NTv2 ascii formatted file.
*  It is intended for the conversion of latitudes and longitudes between
*  the New Zealand geodetic datums NZGD1949 and NZGD2000.  
*
*  This is a minimal implementation of a grid transformation with some
*  significant limitations including:
*	 1) It cannot work with the binary NTv2 format 
*	 2) It does not support subgrids - it only works with a single grid
*	 3) It always loads the entire grid into memory - there is no
*		 load on demand or caching
*	 4) It only calculates the adjustment to coordinates, not the
*		 error of the adjustment.
*
*  This software may be freely used and modified.  It is provided as is, 
*  where is, with no guarantees as to its correct functioning.  Land
*  Information New Zealand accepts no liability for any consequences 
*  of the use of this software.
*
***********************************************************************
*/

// source conversion from http://www.linz.govt.nz/geodetic/software-downloads

class LinzGrid {

	static String distortion;
	static LinzGrid linzGrid;
	
	static double convdeg = 1.0/3600.0;
	static float fconvdeg = 1.0f/3600.0f;

	static final int MAX_DATUM_LEN=16;

	double lat0;	 /* The minimum latitude */
	double lat1;	 /* The maximum latitude */
	double dlat;	 /* The latitude increment */
	double lon0;	 /* The minimum longitude */
	double lon1;	 /* The maximum longitude */
	double dlon;	 /* The longitude increment */
	
	int nlat;		 /* The number of latitude grid values */
	int nlon;		 /* The number of longitude grid values */
	
	char datum0[]=new char[MAX_DATUM_LEN];  /* The source datum for the transformation */
	char datum1[]=new char[MAX_DATUM_LEN];  /* The target datum for the transformation */
	
	float grid[][];	/* The grid data */

	String errMsg;
	
		
	static void init(String nzdistortion){
		distortion=nzdistortion;
	}
	
	static void transform(double lts,double lns,double latlon[]){
		
		if(linzGrid==null){
			linzGrid=new LinzGrid(distortion);		
			distortion="";
		}
		
		while( lns > linzGrid.lon1 ) lns -= 360.0;
		while( lns < linzGrid.lon0 ) lns += 360.0;
		
		LinzGrid.lnzGridCalcOffset(lts,lns,latlon);		
		
		latlon[0]+=lts;
		latlon[1]+=lns;
	}
		
	LinzGrid(String distortion){
		lnzGridCreateFromNTv2Asc(distortion);
	}
	
	
	/***********************************************************************
	*  lnzGridCreateFromNTv2Asc
	* 
	*  Function to load a grid model from an ASCII NTv2 file definition.  The
	*  grid is created even if it cannot be loaded correctly.  (It is only not
	*  created if there is insufficient memory to create the grid structure 
	*  itself).  The lnzGridIsOk function may be used to check that the grid
	*  was loaded correctly, and the lnzGridLastError to discover what went
	*  wrong if it did not 
	* 
	***********************************************************************
	*/

	void lnzGridCreateFromNTv2Asc( String s ){
		 
		int nfile;
		int norec;
		int nsrec;
		
		boolean got_slat;
		boolean got_nlat;
		boolean got_elon;
		boolean got_wlon;
		boolean got_latinc;
		boolean got_loninc;
		boolean got_gscount;

		long gscount;

		datum0[0] = 0;
		datum1[0] = 0;
		
		errMsg="";

		nfile = 0;
		norec = 0;
		nsrec = 0;
		
		gscount=0;

		got_slat = false;
		got_nlat = false;
		got_elon = false;
		got_wlon = false;
		got_latinc = false;
		got_loninc = false;
		got_gscount = false;
				
		// Read the file header */
				
		int p=s.indexOf("GS_COUNT");		
		p=s.indexOf("\r\n",p);

		String args[]=s.substring(0,p).split("\r\n");
		
		for(String l:args){
			String t,v;			
			
			int pp=l.indexOf(" ");			

			if(pp==-1){
				t=l;
				v="";
			}else{
				t=l.substring(0,pp);
				v=l.substring(pp).trim();
			}
			
			if(t.equals("GS_COUNT")) {gscount=Integer.valueOf(v);got_gscount=true;continue;}
			if (t.equals("NUM_OREC")) {norec=Integer.valueOf(v);continue;}			
			if (t.equals("NUM_SREC")) {nsrec=Integer.valueOf(v);continue;}			
			if (t.equals("NUM_FILE")) {nfile=Integer.valueOf(v);continue;}
			
			if(t.equals("S_LAT")) {lat0=Double.valueOf(v)*convdeg;got_slat=true;continue;}
			if(t.equals("N_LAT")) {lat1=Double.valueOf(v)*convdeg;got_nlat=true;continue;}
			if(t.equals("W_LONG")) {lon0=Double.valueOf(v)*-convdeg;got_wlon=true;continue;}
			if(t.equals("E_LONG")) {lon1=Double.valueOf(v)*-convdeg;got_elon=true;continue;}

			if(t.equals("LAT_INC")) {dlat=Double.valueOf(v)*convdeg;got_latinc=true;continue;}
			if(t.equals("LONG_INC")) {dlon=Double.valueOf(v)*convdeg;got_loninc=true;continue;}
		}
		
		if(!(got_gscount&&got_slat&&got_nlat&&got_wlon&&got_elon&&got_latinc&&got_loninc)){
			errMsg="NTv2 distortion grid missing features";
			return;
		}
		
		// Calculate the grid dimensions and compare with the gscount record 

		 nlat = (int) ((lat1 - lat0)/dlat + 1.1);
		 nlon = (int) ((lon1 - lon0)/dlon + 1.1);
		 
		 if(nlat*nlon!=gscount){
			 errMsg="GS_COUNT does not match calculated grid dimensions";
			 return;
		 }

		// Allocate the grid array 

		grid=new float[nlat][];
			
		for(int i=0;i<nlat;i++){
			
			float gv[]=new float[2*nlon];				

			grid[i]=gv;
			
			for(int j=nlon-1;j>=0;j--){

				float dlt,dln;
				String v0,v1;
//				String v2,v3;
				
				v0=s.substring(p+02,p+12);
				v1=s.substring(p+12,p+22);
//				v2=s.substring(p+22,p+32);
//				v3=s.substring(p+32,p+42);
				
				p=s.indexOf("\r\n",p+1);					
				
				dlt=Float.valueOf(v0);
				dln=Float.valueOf(v1);
			
				gv[2*j+0]=dlt*fconvdeg;
				gv[2*j+1]=-dln*fconvdeg;
			}
		}
	}
			

	/***********************************************************************
	*  lnzGridCalcOffset
	*
	*  Calculates the latitude and longitude offset at a specified point on the
	*  grid.  Assumes that the point is within the range defined for the grid.
	***********************************************************************
	*/
		
	static void lnzGridCalcOffset( double lts, double lns, double ltln[]){		
		int nlt, nln;
		double lat0;
		double lon0;
		double dlat;
		double dlon;
		double shlt0;
		double shln0;
		double shlt1;
		double shln1;
		float f[];

			dlat = linzGrid.dlat;
			nlt = (int) Math.floor( (lts - linzGrid.lat0)/dlat );
			if( nlt < 0 ) nlt = 0;
			if( nlt >= linzGrid.nlat-1 ) nlt = linzGrid.nlat-2;
			lat0 = (lts - (linzGrid.lat0 + dlat * nlt))/dlat;

			dlon = linzGrid.dlon;
			nln = (int) Math.floor( (lns - linzGrid.lon0)/dlon );
			if( nln < 0 ) nln = 0;
			if( nln >= linzGrid.nlon-1 ) nln = linzGrid.nlon-2;
			lon0 = (lns - (linzGrid.lon0 + dlon * nln))/dlon;

			f = linzGrid.grid[nlt];// + nln*2;
			shlt0 = f[nln*2+0]*(1-lon0) + f[nln*2+2]*lon0;
			shln0 = f[nln*2+1]*(1-lon0) + f[nln*2+3]*lon0;

			f = linzGrid.grid[nlt+1];// + nln*2;
			shlt1 = f[nln*2+0]*(1-lon0) + f[nln*2+2]*lon0;
			shln1 = f[nln*2+1]*(1-lon0) + f[nln*2+3]*lon0;

			ltln[0] = shlt0*(1-lat0) + shlt1*lat0;
			ltln[1] = shln0*(1-lat0) + shln1*lat0; 

	}


	/***********************************************************************
	*  lnzGridTransform
	*
	*  Uses the grid to transform a latitude and longitude.  This can either be
	*  in the forward direction defined by the From and To datums of the grid,
	*  or in the opposite direction.  The direction is chosen using the 
	*  reverse parameter - 0 (false) transforms in the forward direction, 
	*  non-zero (true) transforms in the reverse direction.  
	*
	*  The function returns non-zero (true) if the transformation is successful,
	*  and 0 (false) if it is not.  When the transformation is not successful
	*  the lnzGridLastError function can be used to ascertain why
	***********************************************************************
	*/

	static int lnzGridTransform( double lts, double lns, double ltln[], boolean reverse ){
		double dlatlon[], ltt, lnt;

		dlatlon=new double[2];
		
		/* Check that the latitude and longitude are within range */

			while( lns > linzGrid.lon1 ) lns -= 360.0;
			while( lns < linzGrid.lon0 ) lns += 360.0;

			if( lns > linzGrid.lon1 || lts < linzGrid.lat0 || lts > linzGrid.lat1 ) {
				linzGrid.errMsg="Point is outside the range of the grid";
				return 0;
				}
			
			/* Now do the calculation */

			lnzGridCalcOffset( lts, lns, dlatlon );
			
			if( ! reverse ) {
				 lts += dlatlon[0]; 
				 lns += dlatlon[1];
				 }
			else {
				 /* For the reverse transformation just iterate once - should be
					 enough for any sensible grid */
				 ltt = lts - dlatlon[0];
				 lnt = lns - dlatlon[1];
				 lnzGridCalcOffset( ltt, lnt, dlatlon );
				 lts = lts - dlatlon[0];
				 lns = lns - dlatlon[1];
				 }

			/* Return the results */

			ltln[0] = lts;
			ltln[1] = lns;
		
		return 1;
	}	
	
	
}


// this code derived from C source published here:
// http://www.linz.govt.nz/sites/default/files/geodetic/software-downloads/nzmg.zip

class NZGrid {
//	final static double NZMG_A = 6378388.0;
//	final static double NZMG_RF = 297.0;

	final static double rad2deg = 180.0/Math.PI ;

	static class complex {
		double real;
		double imag;

		complex(double r, double i) {
			real = r;
			imag = i;
		}
	}

	/*
	 * Coefficients for converting NZMG coordinates to longitude and latitude
	 * From L+S technical note set 1973/32
	 */

	static double a = 6378388.0;
	static double n0 = 6023150.0;
	static double e0 = 2510000.0;
	static double lt0 = -41.0;
	static double ln0 = 173.0;

	static double cfi[] = { 0.6399175073, -0.1358797613, 0.063294409,
			-0.02526853, 0.0117879, -0.0055161, 0.0026906, -0.001333, 0.00067,
			-0.00034 };

	static double cfl[] = { 1.5627014243, 0.5185406398, -0.03333098,
			-0.1052906, -0.0368594, 0.007317, 0.01220, 0.00394, -0.0013 };

	static complex cfb1[] = { new complex(0.7557853228, 0.0),
			new complex(0.249204646, 0.003371507),
			new complex(-0.001541739, 0.041058560),
			new complex(-0.10162907, 0.01727609),
			new complex(-0.26623489, -0.36249218),
			new complex(-0.6870983, -1.1651967) };

	static complex cfb2[] = { new complex(1.3231270439, 0.0),
			new complex(-0.577245789, -0.007809598),
			new complex(0.508307513, -0.112208952),
			new complex(-0.15094762, 0.18200602),
			new complex(1.01418179, 1.64497696),
			new complex(1.9660549, 2.5127645) };

	/*----------------------------------------------------------------*/
	/*
	 * / /* Basic complex arithmetic routines / /* /
	 * /*----------------------------------------------------------------
	 */

	static complex cadd(complex cr, complex c1, complex c2) {
		cr.real=c1.real + c2.real;
		cr.imag=c1.imag + c2.imag;
		return cr;
	}

	static complex csub(complex cr, complex c1, complex c2) {
		cr.real=c1.real - c2.real;
		cr.imag=c1.imag - c2.imag;
		return cr;
	}

	static complex cmult(complex cr, complex c1, complex c2) {
		double r,i;
		r = c1.real * c2.real - c1.imag * c2.imag;
		i = c1.real * c2.imag + c1.imag * c2.real;
		cr.real=r;
		cr.imag=i;
		return cr;
	}

	static complex cdiv(complex cr, complex c1, complex c2) {
		complex temp;
		double cmod2;
		cmod2 = (c2.real * c2.real + c2.imag * c2.imag);
		temp = new complex(c2.real / cmod2, -c2.imag / cmod2);
		cmult(cr, c1, temp);
		return cr;
	}

	static complex cscale(complex cr, complex c1, double sc) {
		cr.real = c1.real * sc;
		cr.imag = c1.imag * sc;
		return cr;
	}

	/*----------------------------------------------------------------*/
	/*
	 * / /* Routines to do the conversions to and from NZMG/ /* /
	 * /*----------------------------------------------------------------
	 */

	static void nzmg_geod(double n, double e, double latlon[]) {
		complex z0, z1, zn, zd, tmp1, tmp2;
		double sum, tmp;
		int i, it;

		z0 = new complex((n - n0) / a, (e - e0) / a);
		z1 = new complex(cfb2[5].real, cfb2[5].imag);

		for (i = 4; i >= 0; i--) {
			cadd(z1, cmult(z1, z1, z0), cfb2[i]);
		}

		cmult(z1, z1, z0);
		
		zn=new complex(0,0);
		zd=new complex(0,0);

		tmp1=new complex(0,0);
		tmp2=new complex(0,0);

		for (it = 1; it>=0; it--) {

			cscale(zn, cfb1[5], 5.0);
			cscale(zd, cfb1[5], 6.0);

			for (i = 4; i!=0; i--) {
				cadd(zn, cmult(tmp1, zn, z1), cscale(tmp2, cfb1[i], (double) i));
				cadd(zd, cmult(tmp1, zd, z1), cscale(tmp2, cfb1[i], (double) (i + 1)));
			}

			cadd(zn, z0, cmult(zn, cmult(zn, zn, z1), z1));
			cadd(zd, cfb1[0], cmult(zd, zd, z1));
			cdiv(z1, zn, zd);
		}

		latlon[1] = ln0 / rad2deg + z1.imag;

		tmp = z1.real;
		sum = cfl[8];

		for (i=7;i>=0;i--){
			sum = sum * tmp + cfl[i];
		}

		sum *= tmp / 3600.0e-5;
		
		latlon[0] = (lt0 + sum) / rad2deg;
				
		latlon[0]*=rad2deg;
		latlon[1]*=rad2deg;
	}

	static void geod_nzmg( double lt, double ln, double northeast[] ) {
		double sum;
		short i;
		complex z0,z1;

		lt = (lt*rad2deg - lt0)*3600.0e-5;
		sum = cfi[9];;
		
		for (i=8;i>=0;i--){
			sum = sum*lt+cfi[i];
		}
		
		sum *= lt;

		z1=new complex( sum, ln-ln0/rad2deg);		
		z0=new complex( cfb1[5].real, cfb1[5].imag);

		for (i=4;i>=0;i--){
			cadd(z0,cmult(z0,z0,z1),cfb1[i]);
		}

		cmult(z0,z0,z1);

		northeast[0] = n0+z0.real*a;
		northeast[1] = e0+z0.imag*a;
	}
	
	static String test_nzmg(){
		
		StringBuffer sb=new StringBuffer();
		
		double d[]=new double[2];
		double d2[]=new double[2];
		
		double lat=-36.852490;
		double lon=174.754652;
		
		lat=-34.44406632;
		lon=172.73919371;
		
		geod_nzmg(lat/rad2deg,lon/rad2deg,d);
				
		sb.append("North="+d[0]+" East="+d[1]+"\n");
		
		nzmg_geod(d[0],d[1],d);

		sb.append("NZ GD1949 Lat="+d[0]+" Lon="+d[1]+"\n");
		
		LinzGrid.transform(d[0],d[1],d2);
		
		sb.append("NZ GD2000 Lat="+d2[0]+" Lon="+d2[1]+"\n");

		return sb.toString();
	}

}


class Schematic{	
		
	// a Cartesian map for geometry in mm units 
	// centered at Cartesian coordinate micro-degree units

	public int clip_x0;
	public int clip_y0;
	public int clip_x1;
	public int clip_y1;

	public int lat_md;
	public int lon_md;
		
	public double meter_scale;
	
	static final int LAYER=0;
	static final int POINT=1;
	static final int POINTER=2;
	static final int EDGE=3;
	static final int PATH=4;

	void drawnz_geod(ShapeImporter.ShapeFile shapeFile){//,double lon,double lat,double east, double north){
        double latlon[]=new double[2];
        int x0,y0,x1,y1;

        NZTM.nztm_geod(shapeFile.miny, shapeFile.minx,latlon);
        y0=(int)((latlon[0])*1e6);
        x0=(int)((latlon[1])*1e6);

        NZTM.nztm_geod(shapeFile.maxy, shapeFile.maxx,latlon);
        y1=(int)((latlon[0])*1e6);
        x1=(int)((latlon[1])*1e6);

        addGeoClip(x0, y0, x1, y1);

        int total=0;
		int totalz=0;

		double longest=0;
		double totalDistance=0;

        for(ShapeImporter.ShapeFile.shapepart p: shapeFile.shapeparts){
            int n=p.xy.length/2;
			int[] points32=new int[n*2];

			double z=0.0;
			if (p.z!=null) z=p.z[0];

            for(int i=0;i<n;i++) {
				points32[i * 2 + 0] = (int) (p.xy[i * 2 + 0] * 1e6);
				points32[i * 2 + 1] = (int) (p.xy[i * 2 + 1] * 1e6);
				assert (p.z[i] == z);

				if (i > 0) {
					double d = Haversine.distance(p.xy[i * 2 + 1], p.xy[i * 2 + 0], p.xy[i * 2 - 1], p.xy[i * 2 - 2]);
					if (d > longest) longest = d;
					totalDistance+=d;
				}
/*
				int dy=points[i*2+1]-points[i*2-1];
					int dx=points[i*2+0]-points[i*2-2];
					int dy=points[i*2+1]-points[i*2-1];
					int d=(int)Math.sqrt(dx*dx+dy*dy);
*/
			}


//          shapeFile.distance+= ShapeImporter.ShapeFile.lineLength(x1 - x0, y1 - y0);

			addLines(points32,(int)z);
            total+=n;
			if(z==0)totalz+=n;
        }

        System.out.println(" total="+total+" totalz="+totalz+" totalDistance="+Math.floor(10e-3*totalDistance)+"km longest="+longest+"m");
    }

	public class DrawOp{		
		int drawType;
		public void write(DataOutputStream out) throws IOException{
		}
	}

	public class Layer extends DrawOp{
		String name;
		String info;
		String details;
		int index;
		Boolean isVisible;
		Layer(String name0,String info0,String details0,int index0){
			drawType=LAYER;
			name=name0;
			info=info0;
			details=details0;
			index=index0;			
			isVisible=false;
		}

		public void write(DataOutputStream out) throws IOException {
			out.writeUTF(name);
			out.writeUTF(info);
			out.writeUTF(details);
			out.writeInt(index);
			out.writeBoolean(isVisible);
		}
	}
			
	public class Point extends DrawOp{
		int x;
		int y;
		int radius;		
		Point(int x0,int y0,int r0){
			drawType=POINT;
			x=x0;
			y=y0;
			radius=r0;
		}
		public void write(DataOutputStream out) throws IOException {
			out.writeInt(x);
			out.writeInt(y);
			out.writeInt(radius);
		}
	}
	
	
	public class Pointer extends DrawOp{
		int x;
		int y;
		int radius;		
		int yaw;
		Pointer(int x0,int y0,int r0,int yaw0){
			drawType=POINTER;
			x=x0;
			y=y0;
			radius=r0;
			yaw=yaw0;
		}
		public void write(DataOutputStream out) throws IOException {
			out.writeInt(x);
			out.writeInt(y);
			out.writeInt(radius);
			out.writeInt(yaw);
		}
	}
	
	public class Edge extends DrawOp{
		int xy[];
		int z;
		public Edge(int count0,int z0){
			drawType=EDGE;
			xy=new int[2*count0];
			z=z0;
		}
		public Edge(int[] xy0,int z0){
			drawType=EDGE;
			xy=xy0;
			z=z0;
		}
		public void write(DataOutputStream out) throws IOException {
			int n=xy.length/2;
			out.writeInt(z);
			out.writeInt(n);
			for(int i=0;i<n;i++)
			{
				out.writeInt(xy[i*2+0]);
				out.writeInt(xy[i*2+1]);
			}
		}
	}

	public class Path extends DrawOp{
		int xyz[];
		public Path(int count0){
			drawType=PATH;
			xyz=new int[3*count0];
		}
		public Path(int[] xyz0){
			drawType=PATH;
			xyz=xyz0;
		}
		public void write(DataOutputStream out) throws IOException {
			int n=xyz.length/3;
			out.writeInt(n);
			for(int i=0;i<n;i++)
			{
				out.writeInt(xyz[i*3+0]);
				out.writeInt(xyz[i*3+1]);
				out.writeInt(xyz[i*3+2]);
			}
		}
	}

	public class Pen{
		int argb;
		int radius;
		Pen(int argb0,int radius0){
			argb=argb0;
			radius=radius0;
		}
	}
			
	public ArrayList<Point> points;
	public ArrayList<Pointer> pointers;
	public ArrayList<Edge> edges;	
	public ArrayList<Layer> layers;	

	public ArrayList<DrawOp> drawList;

	public Pen pens[];


	public void clear(){
		points.clear();
		pointers.clear();
		edges.clear();
		layers.clear();
		drawList.clear();
	}
		
	public void trimLimit(){
		while(points.size()>50){
			points.remove(0);
		}
		while(edges.size()>50){
			edges.remove(0);
		}
	}
	
	int color64(int rgb6){
		int argb;
		int r,g,b;
		
		rgb6=((rgb6>>3)&0x7)|((rgb6<<3)&0x38);
		
		r=(rgb6>>4)&3;
		g=(rgb6>>2)&3;
		b=(rgb6&3);
						
		r=152+(r*180)/6;
		g=152+(g*180)/6;
		b=152+(b*180)/6;
		
		argb=0xaa000000|(r<<16)|(g<<8)|b;

		return argb;
	}

	public Schematic(int lat6,int lon6,double scale){
		lat_md=lat6;
		lon_md=lon6;
		meter_scale=scale;
		reset();
	}
	
	public void reset(){
		points=new ArrayList<Point>();
		pointers=new ArrayList<Pointer>();
		edges=new ArrayList<Edge>();
		layers=new ArrayList<Layer>();
		drawList=new ArrayList<DrawOp>();
		pens=new Pen[64];
		
		for(int i=0;i<64;i++){
			int argb=color64(i);
			Pen pen=new Pen(argb,3);
			pens[i]=pen;
		}		
	}

	public void write(DataOutputStream out) throws IOException{
		out.writeInt(drawList.size());
		for(DrawOp d:drawList)
		{
			out.writeInt(d.drawType);
			d.write(out);
		}
	}
	
	public void addGeoClip(int x0,int y0,int x1,int y1){
		clip_x0=x0;
		clip_y0=y0;
		clip_x1=x1;
		clip_y1=y1;
		
/*
 		addGeoPoint(x0,y0,5);
		addGeoPoint(x1,y1,5);
		
		int dx=(x1-x0)/6;
		int dy=(y1-y0)/6;
		
		addGeoLine(x0,y0,x0+dx,y0,2);
		addGeoLine(x0,y0,x0,y0+dy,2);

		addGeoLine(x1,y0,x1-dx,y0,2);
		addGeoLine(x1,y0,x1,y0+dy,2);

		addGeoLine(x0,y1,x0+dx,y1,2);
		addGeoLine(x0,y1,x0,y1-dy,2);

		addGeoLine(x1,y1,x1-dx,y1,2);
		addGeoLine(x1,y1,x1,y1-dy,2);
		

		addGeoLine(x0,y0,x1,y0,2);
		addGeoLine(x1,y0,x1,y1,2);
		addGeoLine(x1,y1,x0,y1,2);		
		addGeoLine(x0,y1,x0,y0,2);		
*/		
	}
		
	public void addGeoPoint(int x,int y,int r){
		x-=lon_md;
		y-=lat_md;
		addPoint(x,y,r);		
	}
	
	public void addGeoLine(int x0,int y0,int x1,int y1,int r){
		x0-=lon_md;
		y0-=lat_md;
		x1-=lon_md;
		y1-=lat_md;
		addLine(x0,y0,x1,y1,r);		
	}

	public void addPoint(int x,int y,int r){
		Point p=new Point(x,y,r);
		points.add(p);
		drawList.add(p);
	}
	
	public void addPointer(int x,int y,int radius,int yaw){
		Pointer p=new Pointer(x,y,radius,yaw);
		pointers.add(p);
		drawList.add(p);
	}

	public void addEdge(int xy[],int r){
		int n=xy.length/2;
		Edge e=new Edge(n,r);
		System.arraycopy(xy,0,e.xy,0,n*2);
		edges.add(e);
		drawList.add(e);
	}

	public void addLine(int x0,int y0,int x1,int y1,int z){
		Edge e=new Edge(2,z);
		e.xy[0]=x0;
		e.xy[1]=y0;
		e.xy[2]=x1;
		e.xy[3]=y1;
		edges.add(e);
		drawList.add(e);
	}

	public void addLines(int[] xy,int r){
		Edge e=new Edge(xy,r);
		edges.add(e);
		drawList.add(e);
	}

	public Layer createLayer(String name,String info,String details, int penindex){
		return new Layer(name,info,details,penindex);		
	}
		
	public void addLayer(Layer layer){
		layers.add(layer);
		drawList.add(layer);				
	}
	
/*	
	public void setLayer(String name,String info,String details, int penindex){
		Layer layer=new Layer(name,info,details,penindex);
		layers.add(layer);
		drawList.add(layer);		
	}
*/	
}





public class ShapeImporter {

	static List<String> log;

	public static void main( String[] args ) {
//		testHaversine();
//		testWiki();
//		testWiki2();
//		String path=args[0];
//		String path2=args[1];
//		mainargs(["C:\\gis\\linz\\nz-topo-150k.zip","D:\\nz-topo.bin"]);
		ShapeToBin("C:\\gis\\linz\\lds-nz-mainland-coastlines-topo-150k-SHP.zip","D:\\nz-outline.bin");
//		ShapeToBin("C:\\gis\\linz\\lds-nz-mainland-road-centrelines-topo-150k-SHP.zip","D:\\nz-roads.bin");
//		ShapeToBin("C:\\gis\\linz\\nz-tracks-150k.zip","D:\\nz-tracks.bin");
	}

	public static class XMLElement{
		long fileLocation;
		Stack<XMLElement> kids;
		XMLElement parent;
		String name;
		String arguments[];
		String content;
		public XMLElement(String names,long location){
			fileLocation=location;
			String []split=names.trim().split(" ");
			int n=split.length;
			if(n>0) name=split[0];
			if(n>1){
				arguments=new String[n-1];
				System.arraycopy(split,1,arguments,0,n-1);
			}
		}
		public void unlink(){
			kids=null;
			parent=null;
		}

		void setContent(String s) {
			assert (content == null);
			content = s;
		}

		void mineGeoCode(){
			int p=0;
			String s=content;
			while(p<s.length()){
				int q=s.indexOf("{coord|",p);
				if(q==-1){
					break;
				}
				int r=s.indexOf("}",q+7);
				assert(r!=-1);
				parseGeocode(s.substring(q,r+1));
				p=r+1;
			}
		}

		void parseGeocode(String code){
			System.out.println(code);
		}

		XMLElement find(String term){
			for(XMLElement kid:kids) {
				if (kid.name.equals(term)) return kid;
			}
			return null;
		}

		void process()
		{
			if(name.equals("page"))
			{
				XMLElement title=find("title");
				System.out.println("Page "+title.content);
			}
		}
	}

	static final int MaxAngleDepth = 256;

	static class XMLLineParser{
		XMLElement document;
		XMLElement currentElement;

		StringBuffer buffer;
		StringBuffer quoteBuffer;
		boolean inQuotes;

		long startPos;

		void popElement(String tag){
			assert(tag.equals(currentElement.name));
			popElement();
		}

		void popElement(){
			XMLElement e=currentElement;
	//		e.process();
			assert(e.parent!=null);
			currentElement=e.parent;
			e.unlink();
		}

		void pushElement(String tags,long filepos){
			XMLElement element=new XMLElement(tags,filepos);
			element.parent=currentElement;
			if(currentElement.kids==null) currentElement.kids=new Stack<XMLElement>();
			currentElement.kids.add(element);
			currentElement=element;
		}

		XMLLineParser(){
			document=new XMLElement("<root>",0);
			currentElement=document;
			buffer=new StringBuffer();
			quoteBuffer=new StringBuffer();
			inQuotes=false;
		}

		String parseQuotedString(){
			String s=quoteBuffer.toString();
			quoteBuffer.setLength(0);
			return s;
		}

		String parseContent(){
			String s=buffer.toString();
			s=s.trim();
			currentElement.setContent(s);
			buffer.setLength(0);
			return s;
		}

		void parseElement(long offset){
			int l=buffer.length();
			assert(l>0);

			if(buffer.charAt(0)=='/') {
				popElement(buffer.substring(1));
				return;
			}

			boolean terminated=false;
			if(buffer.charAt(l-1)=='/') {
				terminated=true;
				l-=1;
			}

			pushElement(buffer.toString(),offset);

			if(terminated) popElement();

			buffer.setLength(0);
		}

		void parseLine(String line,long offset){
			for(int i=0;i<line.length();i++){
				char c=(char)line.charAt(i);

				if(inQuotes){
					if(c=='"'){
						String string=parseQuotedString();
//						System.out.println("quoted:"+string);
						inQuotes=false;
					}else{
						quoteBuffer.append(c);
					}
					continue;
				}

				switch(c){
					case '<':
						startPos=offset+i;
						parseContent();
						break;
					case '>':
						parseElement(startPos);
						break;
					case '"':
						inQuotes=true;
						break;
					default:
						buffer.append(c);
						break;
				}
			}

		}

		void parseBytes(byte[] line,int length,long offset){

			int start;

			for(int i=0;i<length;i++){
				char c=(char)line[i];

				if(inQuotes){
					if(c=='"'){
						String s=parseQuotedString();
//						System.out.println("quoted:"+s);
						inQuotes=false;
					}else{
						quoteBuffer.append(c);
					}
					continue;
				}

				switch(c) {
					case '<':
						start=i;
						parseContent();
						break;
					case '>':
						parseElement(offset+i);
						break;
					case '"':
						inQuotes = true;
						break;
					default:
						buffer.append(c);
						break;
				}
			}

		}
	}

	static void testWiki(){
		String path="F:/wikipedia/enwiki-20141208-pages-articles-multistream.xml";

		FileInputStream fileIn;
		XMLLineParser parser;

		parser=new XMLLineParser();

		try {
			fileIn = new FileInputStream(path);
		}catch(FileNotFoundException e){
			return;
		}

		long offset=0;
		int count=0;
		byte lineBuffer[]=new byte[65536*64];
		try {
			boolean complete=false;
			while(!complete){
				int n=fileIn.read(lineBuffer);
				if (n==0){
					complete=true;
				}else{
					parser.parseBytes(lineBuffer, n, offset);
				}
				if((count++ & 0xff)==0){
					System.out.print('.');
				}
				offset+=n;
			}
			fileIn.close();
			System.out.println("testWiki:Complete");

		}catch(IOException e){
			System.out.println("testWiki:Exception - "+e.toString());
		}
	}


	static void testWiki2(){
		String path="F:/wikipedia/enwiki-20141208-pages-articles-multistream.xml";

		FileInputStream fileIn;
		XMLLineParser parser;

		parser=new XMLLineParser();

		try {
			fileIn = new FileInputStream(path);
		}catch(FileNotFoundException e){
			return;
		}

		long offset=0;
		int count=0;
		byte lineBuffer[]=new byte[65536*64];
		try {
			boolean complete=false;
			while(!complete){
				int n=fileIn.read(lineBuffer);
				if (n==0){
					complete=true;
				}else{
					parser.parseBytes(lineBuffer, n, offset);
				}
				if((count++ & 0xff)==0){
					System.out.print('.');
				}
				offset+=n;
			}
			fileIn.close();
			System.out.println("testWiki:Complete");

		}catch(IOException e){
			System.out.println("testWiki:Exception - "+e.toString());
		}
	}


	static void testHaversine(){

		double aklat=-36.840417;
		double aklon=174.739869;

		double chchlat=-43.53;
		double chchlon=172.620278;

		double d=1e-6*Haversine.distance(aklat,aklon,chchlat,chchlon);

		System.out.println("distance from AK to CHCH="+d+"km");
	}

	public static void ShapeToBin( String path, String path2 )
	{
		System.out.println("converting shape from "+path);

		int lat6=-36840417;	 //S
		int lon6=174739869;  //E

		Schematic schematic=new Schematic(lat6,lon6,100.0);

		drawShapeArchive(schematic, path, path2, System.out);
	}
	
	static short littleShort(short a){
		int l;
		l=((a&0xff00)>>>8)|((a&0xff)<<8);		
		return (short)l;
	}

	static int littleInt(int a){
		int l;
		l=	((a&0xff)<<24)|
			((a&0xff00)<<8)|
			((a&0xff0000)>>>8)|
			((a&0xff000000)>>>24);
		return l;
	}
	
	static long littleLong(long a){	// reverse order bytes in 64 bit long
		long l;
		l=	((a&0xffL)<<56)|
			((a&0xff00L)<<40)|
			((a&0xff0000L)<<24)|
			((a&0xff000000L)<<8)|
			((a&0xff00000000L)>>>8)|
			((a&0xff0000000000L)>>>24)|
			((a&0xff000000000000L)>>>40)|
			((a&0xff00000000000000L)>>>56);
		return l;
	}

	static double littleDouble(long a){
		return Double.longBitsToDouble(littleLong(a));		
	}
		
	static class wtk{
		String type;
		String name;
		CharSequence value;
		double dvalue;
		ArrayList<wtk> children;
		HashMap<String,wtk> keys;
		
		public wtk(String type0,String name0){
			children=new ArrayList<wtk>();	
			keys=new HashMap<String,wtk>();			
			type=type0;
			name=name0;
		}
		
		public double getDouble(String path){
			wtk self=this;
			String []args=path.split("/");
			for(String arg:args){				
				if(self.keys.containsKey(arg)){
					self=self.keys.get(arg);
				}else{
					return 0;
				}
			}
			double value;
			value=0;
			if(self.value!=null){
				value=Double.parseDouble(self.value.toString());
			}
			return value;
		}
						
		void dump(List<String> log,String indent){
			log.add(indent+"type:"+type+" name="+name+"["+value+"]\n");
			for(wtk child:children){
				child.dump(log, indent+"\t");
			}			
		}
		
		int parse(wtk parent,CharSequence s,int p){
			
			CharSequence stype;
			CharSequence sname;

			if(parent!=null){
				parent.children.add(this);
				parent.keys.put(type,this);
				parent.keys.put(type+"."+name,this);
			}
			
			while(true){
				int q=p;

				while (q<s.length()){
					char c=s.charAt(q++);
					
					if (c==','){
						p=q;
						continue;	// count these guys please...
					}
					
					if (c=='['){
						break;
					}
	
					if(c==']'){
						value=s.subSequence(p,q-1);											
						return q;
					}				
				}
				
				if(q==s.length()) return q;

				stype=s.subSequence(p,q-1);

				p=q;
				q=p;
	
				while (s.charAt(q)!=',' && s.charAt(q)!=']'){
					q++;
				}
				
				sname=s.subSequence(p+1, q-1);	//strip quotes
				p=q+1;
				q=p;
				
				wtk kid;

				kid=new wtk(stype.toString(),sname.toString());
	
				p=kid.parse(this,s,p);
			}
						
		}
	
	}
	
	static class ShapeEntry{
		ZipEntry shp;
		ZipEntry prj;
		ZipEntry dbf;
		ZipEntry txt;
	}
	
	static void drawShapeArchive(Schematic schematic,String path,String path2,PrintStream log){
				
		if(!path.toLowerCase().endsWith(".zip")) return;//todo: load jar files
										
		try{
		
			ShapeEntry shape;
			wtk projection;

			File file=new File(path);
			int p=path.lastIndexOf('/');			
			path=path.substring(p+1,path.length()-4);					
			ZipFile zip=new ZipFile(file);					
			HashMap<String,ShapeEntry> shapes=new HashMap<String,ShapeEntry>();

			for(Enumeration<? extends ZipEntry> e=zip.entries();e.hasMoreElements();){
				ZipEntry entry;
				String name;
				
				entry=(ZipEntry)e.nextElement();				
				name=entry.getName();

				if (name.toLowerCase().endsWith(".shp")){
					name=name.substring(0,name.length()-4);
					
					if(!shapes.containsKey(name)){
						shapes.put(name, new ShapeEntry());
					}
					shape=shapes.get(name);
					shape.shp=entry;
					continue;
				}				
				if (name.toLowerCase().endsWith(".prj")){
					name=name.substring(0,name.length()-4);
					
					if(!shapes.containsKey(name)){
						shapes.put(name, new ShapeEntry());
					}
					shape=shapes.get(name);
					shape.prj=entry;
					continue;
				}				
				if (name.toLowerCase().endsWith(".dbf")){
					name=name.substring(0,name.length()-4);
					
					if(!shapes.containsKey(name)){
						shapes.put(name, new ShapeEntry());
					}
					shape=shapes.get(name);
					shape.dbf=entry;
					continue;
				}
				if (name.toLowerCase().endsWith(".txt")){
					name=name.substring(0,name.length()-4);

					if(!shapes.containsKey(name)){
						shapes.put(name, new ShapeEntry());
					}
					shape=shapes.get(name);
					shape.txt=entry;
					continue;
				}
			}

			DataOutputStream out=new DataOutputStream(new FileOutputStream(path2));

			ArrayList<DBFField> fields;
			String text;
			int pencount=0;
			
			ArrayList<Schematic.Layer> lines;
			ArrayList<Schematic.Layer> points;
			
			lines=new ArrayList<Schematic.Layer>();
			points=new ArrayList<Schematic.Layer>();
			
			for(String name:shapes.keySet()){
				shape=shapes.get(name);

				ZipEntry txt=shape.txt;
				text=readTXT(zip.getInputStream(txt),txt.getSize());
//				System.out.println(text);

				ZipEntry dbf=shape.dbf;
				fields=readDBF(zip.getInputStream(dbf));
				
				ZipEntry shp=shape.shp;
				ShapeFile shapefile;
				
				shapefile=new ShapeFile();	
				shapefile.read(zip.getInputStream(shp));
			
				ZipEntry prj=shape.prj;
				
				if(prj!=null){
					projection=readProjection(zip.getInputStream(prj),(int)(prj.getSize()));
//					projection.dump(log,"");
					
					double lon,lat;
					double east,north;
					
					lon=projection.getDouble("PROJCS/PROJECTION/PARAMETER.Longitude_Of_Origin");
					lat=projection.getDouble("PROJCS/PROJECTION/PARAMETER.Latitude_Of_Origin");
					
					east=projection.getDouble("PROJCS/PROJECTION/PARAMETER.False_Easting");
					north=projection.getDouble("PROJCS/PROJECTION/PARAMETER.False_Northing");
				}
				
				String title=name;

				int i=name.lastIndexOf('/');
				if (i>-1) title=name.substring(i+1);
				
 				int distance;
 				int dots;
				String info;	
				String details;
				
				distance=shapefile.distance;
				
				dots=shapefile.shapepoints.size();

				distance=shapefile.distance-distance;				
				
				info="";
				
				if(dots>0) info+="points:"+dots+"\n";
				if (distance>0) info+="distance:"+distance+"m\n";
								
				details="";
				for(DBFField field:fields){
					details+=field.name+":"+field.value+"\n";
				}

//				if (distance>0){// || dots>0){
//					drawing.setLayer(layer,info,details,(pencount++)&63);							

				Schematic.Layer layer=schematic.createLayer(title,info,details,(pencount++)&63);

				if(log!=null){
					log.println(title);
//					log.println(details);
				}

				if (distance>0){
					lines.add(layer);
				}else{
					points.add(layer);
				}

				schematic.addLayer(layer);
				schematic.drawnz_geod(shapefile);

				schematic.write(out);

				schematic.clear();
			}

			out.close();

		}catch(IOException e){
			
		}
	}
	
/*	
	static void drawShapeFile(Schematic drawing,String path,TextView log){
		
		
		if(!path.endsWith(".shp")) return;
		
		path=path.substring(0,path.length()-4);
		
		ShapeFile shape=new ShapeFile();
		
		shape.load(path+".shp");
		
		wtk projection=loadProjection(path+".prj");		
		
		projection.dump(log,"");
				
		double lon,lat;
		double east,north;
		
		lon=projection.getDouble("PROJCS/PROJECTION/PARAMETER.Longitude_Of_Origin");
		lat=projection.getDouble("PROJCS/PROJECTION/PARAMETER.Latitude_Of_Origin");
		east=projection.getDouble("PROJCS/PROJECTION/PARAMETER.False_Easting");
		north=projection.getDouble("PROJCS/PROJECTION/PARAMETER.False_Northing");

		shape.drawnz_gd49(drawing);//,lon,lat,east,north);
		
//		loadDBF(path+".dbf");		
	}
*/
	
	static wtk loadProjection(String path){		
		try{
			FileInputStream stream=new FileInputStream(path);			
			int length=(int)stream.getChannel().size();			
			return readProjection(stream,length);
		}catch(IOException e){		
			return null;
		}
	}
	
	static wtk readProjection(InputStream stream,int length) throws IOException{
		byte[] buffer=new byte[length];
		length=stream.read(buffer);		
		stream.close();		
		String s=new String(buffer);		
		wtk projection;		
		projection=new wtk("file","");		
		projection.parse(null, s, 0);		
		return projection;	
	}
	
	static class DBFField{
		byte fieldname[];
		byte fieldtype;
		int displacement;
		byte fieldlength;
		byte numdp;
		byte fieldflags;
		int autonext;
		int autostep;
		
		String name;
		String value;
		
		void read(DataInputStream in) throws IOException{
			int length=fieldlength&255;
			byte[] bytes=new byte[length];
			in.read(bytes);
			
			
			if (name.equals("COLOUR")){
				name=name;
			}
			
			switch(fieldtype){
			case 'C':
				value=new String(bytes);
				break;
			case 'N':
				value=new String(bytes);
				break;
			case 'F':
				value=new String(bytes);
				break;
			case 'L':
				if(bytes[0]!=0) value="true";else value="false";
				break;
			case 'D':
				value=new String(bytes);
				break;
			case 'T':
				value=new String(bytes);
				break;
			default:
				value="dbftype:"+String.valueOf((char)fieldtype);
				break;
			}
			value=value.trim();
		}
		
		void readDescriptor(DataInputStream in) throws IOException{
			fieldname=new byte[11];
			in.read(fieldname);
			
			name=new String(fieldname).trim();
			
			fieldtype=in.readByte();
			displacement=littleInt(in.readInt());
			fieldlength=in.readByte();
			numdp=in.readByte();
			fieldflags=in.readByte();
			autonext=littleInt(in.readInt());
			autostep=in.readByte();
			in.skip(8);						
		}
	}

	static String readTXT(InputStream stream,long count){

		String result="";

		try{

			byte[] bytes=new byte[(int)count];
			stream.read(bytes);
			result=new String(bytes,"UTF-8");

		}catch(IOException e){

		}

		return result;
	}

	static ArrayList<DBFField> readDBF(InputStream stream){
		
		ArrayList<DBFField> fields=new ArrayList<DBFField>();
		
		try{
			BufferedInputStream bstream=new BufferedInputStream(stream);
			DataInputStream input=new DataInputStream(bstream);			

			byte filetype;
			byte year;	//+1900
			byte month;
			byte day;
			int recordcount;
			short firstposition;
			short recordlen;
			
			filetype=input.readByte();
			year=input.readByte();
			month=input.readByte();
			day=input.readByte();
			
			recordcount=littleInt(input.readInt());
			firstposition=littleShort(input.readShort());
			
			recordlen=littleShort(input.readShort());
			
			input.skip(16);
			
			byte tableflags;
			byte codepagemark;
			
			tableflags=input.readByte();
			codepagemark=input.readByte();
			
			long n=input.skip(2);
			
			int fieldcount=0;
			int len=recordlen;

			DBFField sub;
			
			while(recordlen>1){
				sub=new DBFField();
				sub.readDescriptor(input);				
				recordlen-=(sub.fieldlength&255);	//convert unsigned byte
				fieldcount++;
				
				fields.add(sub);
			}
			
			byte terminator;
			
			terminator=input.readByte();
			
//			input.skip(263);
			
			byte deleted=input.readByte();
			
			for(DBFField r:fields){
				r.read(input);				
			}
			
			input.close();
			
		}catch(IOException e){
			
		}
		
		return fields;		
	}
	
	static class ShapeFile{
		int filecode;
		int unused[]=new int[5];
		int filelength;
		int version;
		int shapetype;
		double minx,miny,maxx,maxy;
		double minz,maxz;
		double minm,maxm;
		int distance;
		int points;

		ArrayList<shapepart> shapeparts;
		ArrayList<shapepoint> shapepoints;

		static class shapepoint{
			double x,y;
			
			shapepoint(double x0,double y0){
				x=x0;
				y=y0;
			}
		}
		
		static class shapepart{
			int parts[];
			double xy[];
			double z[];

			shapepart(int numparts,int numpoints,boolean hasz){
				parts=new int[numparts];
				xy=new double[numpoints*2];
				if (hasz) z=new double[numpoints];
			}
		}
		
		ShapeFile(){
			shapeparts=new ArrayList<shapepart>();
			shapepoints=new ArrayList<shapepoint>();
		}
		
		void drawnz_gd49(Schematic drawing){//,double lon,double lat,double east, double north){
			
			double latlon[]=new double[2];
			int x0,y0,x1,y1;			

			NZGrid.nzmg_geod(miny,minx,latlon);			
			LinzGrid.transform(latlon[0],latlon[1],latlon);

			y0=(int)((latlon[0])*1e6);
			x0=(int)((latlon[1])*1e6);													

			NZGrid.nzmg_geod(maxy,maxx,latlon);			
			LinzGrid.transform(latlon[0],latlon[1],latlon);
			
			y1=(int)((latlon[0])*1e6);
			x1=(int)((latlon[1])*1e6);													

			drawing.addGeoClip(x0,y0,x1,y1);
			
			for(shapepart p:shapeparts){
				
				double xm,ym;
				int r;				
				int n=p.xy.length/2;

				r=8;
				x1=0;
				y1=0;
				
				for(int i=0;i<n;i++){					
					x0=x1;
					y0=y1;
					
					xm=p.xy[i*2+0];
					ym=p.xy[i*2+1];
					
					NZGrid.nzmg_geod(ym,xm,latlon);
					LinzGrid.transform(latlon[0],latlon[1],latlon);

					y1=(int)((latlon[0])*1e6);
					x1=(int)((latlon[1])*1e6);
					
					if(i>0){
						drawing.addGeoLine(x0, y0, x1, y1, r);						
						distance+=lineLength(x1-x0,y1-y0);
					}
				}
				
			}	
			
			for(shapepoint p:shapepoints){
				NZGrid.nzmg_geod(p.y,p.x,latlon);
				LinzGrid.transform(latlon[0],latlon[1],latlon);

				y0=(int)((latlon[0])*1e6);
				x0=(int)((latlon[1])*1e6);
				
				drawing.addGeoPoint(x0, y0, 5);

			}
		}
		
		void drawnz_tm2000(Schematic drawing){//,double lon,double lat,double east, double north){	
			double latlon[]=new double[2];
			int x0,y0,x1,y1;			

			NZTM.nztm_geod(miny,minx,latlon);
			y0=(int)((latlon[0])*1e6);
			x0=(int)((latlon[1])*1e6);													

			NZTM.nztm_geod(maxy,maxx,latlon);
			y1=(int)((latlon[0])*1e6);
			x1=(int)((latlon[1])*1e6);													

			drawing.addGeoClip(x0,y0,x1,y1);
			
			for(shapepart p:shapeparts){
				
				double xm,ym;
				int r;				
				int n=p.xy.length/2;

				r=4;
				x1=0;
				y1=0;
				
				for(int i=0;i<n;i++){
					
					x0=x1;
					y0=y1;
					
					xm=p.xy[i*2+0];
					ym=p.xy[i*2+1];
										
					NZTM.nztm_geod(ym,xm,latlon);
					
					y1=(int)((latlon[0])*1e6);
					x1=(int)((latlon[1])*1e6);
					
					if(i>0){
						drawing.addGeoLine(x0, y0, x1, y1, r);						
						distance+=lineLength(x1-x0,y1-y0);
					}
				}
				
			}			
		}


		/*
		private void convertCoordinate(double latZone, double longZone, double _northing, double _easting, double[] latlon) {
			String UTM;
			double clatlon[];			
			CoordinateConversion converter=new CoordinateConversion();			
			UTM=converter.latLon2MGRUTM(-36,174);//latLon2UTM(-36,174);
//			UTM = ((int)longZone) + " S " + ((int)latZone) + " " + ((int) _easting) + " "  + ((int) _northing);						
			UTM="60 H "+((int)longZone+" "+((int)latZone));			
			clatlon=converter.utm2LatLon(UTM);			
			latlon[0]=clatlon[0];
			latlon[1]=clatlon[1];
					
		}
*/
		static int lineLength(int dx,int dy){
			long dxdxdydy=dx*dx+dy*dy;
			return (int)Math.sqrt(dxdxdydy);
		}
		
		void load(String path){
			try{
				InputStream stream=new FileInputStream(path);
				read(stream);		
			}catch(IOException e){
				
			}
		}
		
		void read(InputStream stream) throws IOException{
				
			BufferedInputStream bstream=new BufferedInputStream(stream);
			DataInputStream input=new DataInputStream(bstream);			
			
			filecode=input.readInt();
			for(int i=0;i<5;i++){
				unused[i]=input.readInt();
			}
			filelength=input.readInt();

			version=littleInt(input.readInt());
			shapetype=littleInt(input.readInt());
			
			minx=littleDouble(input.readLong());
			miny=littleDouble(input.readLong());
			maxx=littleDouble(input.readLong());
			maxy=littleDouble(input.readLong());
			
			minz=littleDouble(input.readLong());
			maxz=littleDouble(input.readLong());

			minm=littleDouble(input.readLong());
			maxm=littleDouble(input.readLong());
			
			filelength-=50;
			
			while (filelength>0){
				
				int number=input.readInt();
				int length=input.readInt();

				filelength-=4;
				filelength-=length;				
				
				int type=littleInt(input.readInt());
				length-=2;
								
				switch (type){
				case 1:					//Point
					double px,py;
					px=littleDouble(input.readLong());
					py=littleDouble(input.readLong());
					length-=8;
					shapepoint point=new shapepoint(px,py);
					shapepoints.add(point);
					break;
				case 3:					//Polyline
					while (length>0){
						double ax,ay,bx,by;
						int nparts;
						int npoints;
						ax=littleDouble(input.readLong());
						ay=littleDouble(input.readLong());
						bx=littleDouble(input.readLong());
						by=littleDouble(input.readLong());
						nparts=littleInt(input.readInt());
						npoints=littleInt(input.readInt());							
						length-=20;

						shapepart part=new shapepart(nparts,npoints,false);
						shapeparts.add(part);
						
						for(int i=0;i<nparts;i++){
							part.parts[i]=input.readInt();
							length-=2;
						}
						for(int i=0;i<npoints;i++){
							part.xy[i*2+0]=littleDouble(input.readLong());
							part.xy[i*2+1]=littleDouble(input.readLong());								
							length-=8;
						}
					}
					break;
				case 8:			//MultiPoint
					while (length>0){
						double ax,ay,bx,by;
						int n;
						ax=littleDouble(input.readLong());
						ay=littleDouble(input.readLong());
						bx=littleDouble(input.readLong());
						by=littleDouble(input.readLong());
						n=littleInt(input.readInt());
						length-=18;
						for(int i=0;i<n;i++){
							double x,y;
							x=littleDouble(input.readLong());
							y=littleDouble(input.readLong());
							length-=8;
						}
					}
					break;
				case 13:		//PolylineZ
					while (length>0){
						double ax,ay,bx,by;
						int nparts;
						int npoints;
						ax=littleDouble(input.readLong());
						ay=littleDouble(input.readLong());
						bx=littleDouble(input.readLong());
						by=littleDouble(input.readLong());
						nparts=littleInt(input.readInt());
						npoints=littleInt(input.readInt());
						length-=20;

						shapepart part=new shapepart(nparts,npoints,true);
						shapeparts.add(part);

						for(int i=0;i<nparts;i++){
							part.parts[i]=input.readInt();
							length-=2;
						}
						for(int i=0;i<npoints;i++){
							part.xy[i*2+0]=littleDouble(input.readLong());
							part.xy[i*2+1]=littleDouble(input.readLong());
							length-=8;
						}

						double z0=littleDouble(input.readLong());
						double z1=littleDouble(input.readLong());
						length-=8;

						for(int i=0;i<npoints;i++){
							part.z[i]=littleDouble(input.readLong());
							length-=4;
						}

						if(length>0) {
							double m0 = littleDouble(input.readLong());
							double m1 = littleDouble(input.readLong());
							assert (length==npoints*4);
							length -= npoints*4;
						}

					}
					break;

				default:
					System.out.println("skipping "+length+" words");
					input.skip(length*2);
				}
				
			}
			
			input.close();
	
		}
	}

}



#end