
#include "PROPOSAL/scattering/Coefficients.h"

//----------------------------------------------------------------------------//
//-----------------------------Coefficients-----------------------------------//
//---for calculating the power series approximation of the moliere function---//
//----------------------------------------------------------------------------//

const double PROPOSAL::c1[100] = {
    0.01824498698928826,    -1.054734960967865,      1.378945800806554,      -0.8101747070430586,
    0.3020799653590784,     -0.08217510264333025,    0.01757489395499939,    -0.003095373240445565,
    0.0004633127963647091,  -6.029130794154548e-05,  6.939349333147516e-06,  -7.159829943698265e-07,
    6.694120779750297e-08,  -5.721860009237694e-09,  4.504494235551189e-10,  -3.286570977596057e-11,
    2.234424657611573e-12,  -1.422140651267253e-13,  8.50844668823957e-15,   -4.80239726059346e-16,
    2.56544019782712e-17,   -1.3008032373069e-18,    6.276721156927733e-20,  -2.888980198088948e-21,
    1.271082178072295e-22,  -5.356321836042788e-24,  2.165708913690074e-25,  -8.415665707369898e-27,
    3.14768814769592e-28,   -1.134804220079789e-29,  3.948607075433194e-31,  -1.327667573801528e-32,
    4.318678128634822e-34,  -1.360474072770111e-35,  4.154710513947732e-37,  -1.231145280289021e-38,
    3.543063949967192e-40,  -9.910855129282805e-42,  2.69678926347067e-43,   -7.143475307428035e-45,
    1.843336870282648e-46,  -4.636847647068766e-48,  1.137731434272442e-49,  -2.724695331159021e-51,
    6.372463895718094e-53,  -1.4562852800865e-54,    3.253589567012378e-56,  -7.110068913054863e-58,
    1.520504345733737e-59,  -3.183490667084008e-61,  6.528486713873094e-63,  -1.311890818170701e-64,
    2.584252665251881e-66,  -4.99221608462446e-68,   9.460964789499932e-70,  -1.759614514252362e-71,
    3.212849154606866e-73,  -5.761014854313268e-75,  1.014807133464239e-76,  -1.756624689658179e-78,
    2.98893079441324e-80,   -5.000577728087579e-82,  8.228369765510281e-84,  -1.332031746609897e-85,
    2.121957008008998e-87,  -3.327287074593805e-89,  5.136681841644386e-91,  -7.809396838908658e-93,
    1.169486848348948e-94,  -1.72549543381347e-96,   2.508809249655915e-98,  -3.595413291827729e-100,
    5.079801219388072e-102, -7.076983722567338e-104, 9.723837840810993e-106, -1.317945326279369e-107,
    1.762410958111165e-109, -2.325652802263962e-111, 3.028909076825982e-113, -3.89408163088736e-115,
    4.942802177984765e-117, -6.195278874139763e-119, 7.668956698453442e-121, -9.377048488608183e-123,
    1.132701624601603e-124, -1.351910188741138e-126, 1.594502032991125e-128, -1.858693324663112e-130,
    2.141681719707223e-132, -2.43963241933955e-134,  2.747720630653711e-136, -3.060234006823078e-138,
    3.370734378882746e-140, -3.672273506135163e-142, 3.957653085865992e-144, -4.219715312480803e-146,
    4.451647266046611e-148, -4.647280664772496e-150, 4.80136823945151e-152,  -4.909819238915968e-154
};

const double PROPOSAL::c2[100] = {
    0.3692951315189029,     -2.901210618562379,      4.763691522462663,      -3.668389620520657,
    1.743233030563621,      -0.5857757559172652,     0.1507057475725596,     -0.03124919421553912,
    0.005411101880491738,   -0.0008029915660482544,  0.0001041435915389889,  -1.198693445962836e-05,
    1.239576100587234e-06,  -1.163301889847139e-07,  9.990755927592503e-09,  -7.907851249726336e-10,
    5.803579436334176e-11,  -3.969886777147483e-12,  2.542633424164171e-13,  -1.530925400639093e-14,
    8.696260972023862e-16,  -4.675164455450479e-17,  2.385523336370255e-18,  -1.158267999875986e-19,
    5.363958217246529e-21,  -2.374296161332396e-22,  1.006470730715194e-23,  -4.093159567679296e-25,
    1.5996354171463e-26,    -6.016551229383919e-28,  2.180970406636743e-29,  -7.629492110705818e-31,
    2.578781877602269e-32,  -8.431429670892704e-34,  2.669429048218415e-35,  -8.192196123057652e-37,
    2.439244055889828e-38,  -7.052895752459682e-40,  1.98198110121125e-41,   -5.417437723374357e-43,
    1.441367960601787e-44,  -3.735506587014256e-46,  9.436466002585026e-48,  -2.325045788414374e-49,
    5.590871105668466e-51,  -1.312817566476688e-52,  3.011935532920134e-54,  -6.755103130065185e-56,
    1.481773486168858e-57,  -3.180564595352823e-59,  6.683429378680969e-61,  -1.375495310358957e-62,
    2.773751380431616e-64,  -5.482786499876722e-66,  1.062748090934042e-67,  -2.020774364918115e-69,
    3.770691103605001e-71,  -6.907025753601122e-73,  1.242436024375922e-74,  -2.195383992072398e-76,
    3.811853327900785e-78,  -6.505522184103775e-80,  1.091628995757091e-81,  -1.801512577182476e-83,
    2.924740086946532e-85,  -4.672395489277705e-87,  7.346918415137358e-89,  -1.137343481536269e-90,
    1.733816262095051e-92,  -2.603397903194606e-94,  3.851253561734265e-96,  -5.61413579760181e-98,
    8.066318236042616e-100, -1.142534156297296e-101, 1.595701569049596e-103, -2.197898380015261e-105,
    2.986204180183809e-107, -4.002834291275826e-109, 5.294562476317114e-111, -6.911669661645124e-113,
    8.906363201403711e-115, -1.133064328971227e-116, 1.423363576915385e-118, -1.765846157643044e-120,
    2.163876866238606e-122, -2.619510733347758e-124, 3.133137855471063e-126, -3.703162047314654e-128,
    4.325741534530339e-130, -4.994619251572251e-132, 5.701067045150251e-134, -6.433962204999298e-136,
    7.180006537985007e-138, -7.924088243222738e-140, 8.649775953179418e-142, -9.339923463142228e-144,
    9.977353925282273e-146, -1.054558462375476e-147, 1.102954869090941e-149, -1.141626881676896e-151
};

const double PROPOSAL::c2large[50] = { 0,
                                       0,
                                       5.317361552716548,
                                       39.88021164537411,
                                       279.1614815176188,
                                       2093.711111382141,
                                       17273.11666890266,
                                       157185.3616870142,
                                       1571853.616870142,
                                       17178114.5272237,
                                       203990110.0107814,
                                       2617873078.471694,
                                       36126648482.90939,
                                       533689125315.7068,
                                       8405603723722.382,
                                       140632216146893.7,
                                       2491199257459260,
                                       4.658542611448816e+16,
                                       9.171505766289856e+17,
                                       1.896343692265226e+19,
                                       4.108744666574657e+20,
                                       9.309550415580998e+21,
                                       2.201708673284906e+23,
                                       5.425639230594947e+24,
                                       1.390936602752523e+26,
                                       3.704124648634435e+27,
                                       1.023264434185263e+29,
                                       2.928582810638222e+30,
                                       8.673110631505504e+31,
                                       2.65493553219974e+33,
                                       8.39149266427418e+34,
                                       2.735915970369392e+36,
                                       9.192677660441157e+37,
                                       3.180369932523594e+39,
                                       1.132012922857617e+41,
                                       4.142138195001734e+42,
                                       1.55695665094477e+44,
                                       6.007628448859746e+45,
                                       2.378019594340316e+47,
                                       9.65026059703239e+48,
                                       4.012476774555574e+50,
                                       1.708389149781931e+52,
                                       7.444305720174763e+53,
                                       3.318163098443751e+55,
                                       1.512134326290795e+57,
                                       7.041974391621668e+58,
                                       3.349739182196398e+60,
                                       1.626856662820051e+62,
                                       8.063550415716772e+63,
                                       4.077239907010832e+65 };

const double PROPOSAL::s2large[50] = { 0,
                                       0,
                                       -0.3515783203226215,
                                       -0.5515783203226214,
                                       -0.6944354631797642,
                                       -0.8055465742908754,
                                       -0.8964556651999662,
                                       -0.9733787421230431,
                                       -1.04004540878971,
                                       -1.098868938201474,
                                       -1.151500517148843,
                                       -1.19911956476789,
                                       -1.242597825637456,
                                       -1.282597825637456,
                                       -1.319634862674493,
                                       -1.354117621295182,
                                       -1.386375685811311,
                                       -1.416678716114342,
                                       -1.44525014468577,
                                       -1.472277171712797,
                                       -1.497918197353823,
                                       -1.522308441256262,
                                       -1.54556425520975,
                                       -1.567786477431973,
                                       -1.589063073176654,
                                       -1.609471236441959,
                                       -1.629079079579214,
                                       -1.647947004107516,
                                       -1.666128822289334,
                                       -1.683672681938457,
                                       -1.70062183448083,
                                       -1.717015277103781,
                                       -1.732888292976797,
                                       -1.748272908361412,
                                       -1.76319828149574,
                                       -1.777691035118929,
                                       -1.791775542161182,
                                       -1.805474172298168,
                                       -1.818807505631502,
                                       -1.831794518618515,
                                       -1.844452746466616,
                                       -1.856798425478962,
                                       -1.868846618250046,
                                       -1.880611324132399,
                                       -1.892105577005962,
                                       -1.903341532062142,
                                       -1.914330543051153,
                                       -1.925083231223196,
                                       -1.93560954701267,
                                       -1.945918825363185 };

const double PROPOSAL::C1large[50] = { 0,
                                       -0.443113462726379,
                                       -0.6646701940895685,
                                       -1.661675485223921,
                                       -5.815864198283724,
                                       -26.17138889227676,
                                       -143.9426389075222,
                                       -935.6271528988941,
                                       -7017.203646741706,
                                       -59646.2309973045,
                                       -566639.1944743927,
                                       -5949711.541981123,
                                       -68421682.73278293,
                                       -855271034.1597866,
                                       -11546158961.15712,
                                       -167419304936.7782,
                                       -2594999226520.062,
                                       -42817487237581.03,
                                       -749306026657668,
                                       -1.386216149316686e+16,
                                       -2.703121491167537e+17,
                                       -5.541399056893451e+18,
                                       -1.191400797232092e+20,
                                       -2.680651793772207e+21,
                                       -6.299531715364686e+22,
                                       -1.543385270264348e+24,
                                       -3.935632439174088e+25,
                                       -1.042942596381133e+27,
                                       -2.868092140048117e+28,
                                       -8.174062599137132e+29,
                                       -2.411348466745454e+31,
                                       -7.354612823573634e+32,
                                       -2.316703039425695e+34,
                                       -7.529284878133508e+35,
                                       -2.522310434174725e+37,
                                       -8.701970997902803e+38,
                                       -3.089199704255495e+40,
                                       -1.127557892053256e+42,
                                       -4.228342095199709e+43,
                                       -1.627911706651888e+45,
                                       -6.430251241274957e+46,
                                       -2.604251752716358e+48,
                                       -1.080764477377288e+50,
                                       -4.593249028853476e+51,
                                       -1.998063327551262e+53,
                                       -8.891381807603116e+54,
                                       -4.045578722459418e+56,
                                       -1.881194105943629e+58,
                                       -8.935672003232238e+59,
                                       -4.333800921567636e+61 };
