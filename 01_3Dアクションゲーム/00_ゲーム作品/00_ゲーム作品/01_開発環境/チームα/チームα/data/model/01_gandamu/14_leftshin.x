xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 130;
 2.69168;-0.58366;-13.60277;,
 9.30251;-11.66933;-10.99255;,
 -8.24592;-13.20461;-10.99255;,
 -3.66046;-1.13937;-13.60277;,
 -12.21887;-35.35211;-15.40279;,
 -9.55379;-23.90745;-10.46388;,
 -10.10665;-26.56536;-18.88252;,
 -7.61021;-24.10526;-12.93357;,
 -7.99601;-23.38758;-16.32930;,
 -5.58761;-22.28553;-20.46362;,
 8.27546;-20.99550;-20.53240;,
 10.55981;-22.47176;-12.93375;,
 11.32734;-21.70652;-16.30982;,
 5.71198;-164.24110;-9.28786;,
 8.97180;-163.95590;-12.53045;,
 5.71198;-164.24110;12.04686;,
 8.93000;-163.95957;15.33621;,
 18.52390;-163.12021;-12.53045;,
 18.56565;-163.11658;15.33621;,
 21.78372;-162.83500;-9.28791;,
 21.78372;-162.83500;12.04686;,
 13.44991;-24.42454;-18.95413;,
 17.06093;-32.79044;-15.40280;,
 12.45070;-21.98470;-10.46596;,
 -10.49890;-1.73769;13.16015;,
 -4.00744;-1.16972;13.66012;,
 -10.49890;-1.73769;-8.40561;,
 -3.66046;-1.13937;-13.60277;,
 3.03867;-0.55329;13.66012;,
 2.69168;-0.58366;-13.60277;,
 9.53016;0.01466;13.16014;,
 9.53016;0.01466;-8.40562;,
 28.54393;-130.64085;30.75063;,
 33.21746;-130.26734;26.34266;,
 24.41324;-109.10897;24.70379;,
 21.72062;-109.29422;27.75994;,
 18.79832;-83.83527;21.26111;,
 15.58756;-84.29991;24.56088;,
 33.13726;-130.05569;-26.08762;,
 28.49061;-130.68089;-30.49836;,
 21.69356;-109.34693;-19.79162;,
 24.33635;-108.80449;-16.71409;,
 15.41653;-84.13111;-21.41355;,
 18.79832;-83.83527;-18.05684;,
 -13.87335;-13.69697;14.31690;,
 -8.46530;-13.22380;18.57030;,
 -8.46530;-13.22380;18.57030;,
 -11.72223;-35.30865;19.86213;,
 -8.43327;-35.02091;23.08002;,
 -8.24592;-13.20461;-10.99255;,
 -13.82993;-13.69314;-6.75439;,
 18.68701;-69.56967;19.20173;,
 15.42365;-69.85519;22.45997;,
 15.36206;-69.86053;-30.85379;,
 18.68701;-69.56967;-27.35556;,
 -6.49218;-133.70051;-30.49875;,
 -11.20334;-134.15369;-26.10746;,
 -6.20697;-111.78792;-16.73374;,
 -3.50224;-111.49299;-19.79201;,
 -3.50224;-111.49299;-19.79201;,
 -6.20697;-111.78792;-16.73374;,
 -5.06595;-85.92311;-17.87031;,
 -1.70898;-85.62940;-21.26343;,
 -11.16823;-133.96870;26.30940;,
 -6.54272;-133.74595;30.75710;,
 -3.52675;-111.55344;27.76637;,
 -6.18790;-111.52739;24.67084;,
 -3.52675;-111.55344;27.76637;,
 -1.75869;-85.82117;24.56137;,
 -5.06595;-85.92311;21.26111;,
 -1.75869;-85.82117;24.56137;,
 -4.17016;-71.56941;22.45998;,
 -7.43351;-71.85493;19.20173;,
 -1.70898;-85.62940;-21.26343;,
 -5.06595;-85.92311;-17.87031;,
 -7.43351;-71.85493;-27.56775;,
 -4.10430;-71.56366;-30.85379;,
 16.44851;-43.96284;-35.86971;,
 19.66816;-43.56369;-32.59207;,
 19.70179;-43.67819;21.47759;,
 16.45521;-43.96227;24.73274;,
 -12.92885;-46.53303;21.47671;,
 -9.68138;-46.24893;24.73274;,
 -8.43327;-35.02091;23.08002;,
 -9.68138;-46.24893;24.73274;,
 -4.17016;-71.56941;22.45998;,
 -9.67558;-46.24844;-35.86971;,
 -12.91561;-46.41436;-32.59207;,
 -9.28833;-26.10642;-30.23048;,
 -5.89677;-26.95146;-33.44315;,
 -12.91561;-46.41436;-32.59207;,
 -9.67558;-46.24844;-35.86971;,
 -4.10430;-71.56366;-30.85379;,
 -7.43351;-71.85493;-27.56775;,
 16.56436;-32.83392;19.86212;,
 13.27542;-33.12167;23.08002;,
 14.92985;-11.17700;14.31690;,
 9.52960;-11.64948;18.57030;,
 9.37216;-25.61560;-33.44315;,
 12.57373;-24.19461;-30.33701;,
 3.03867;-0.55329;13.66012;,
 14.88647;-11.18078;-6.75434;,
 -6.64680;-15.37593;-24.79845;,
 -0.41595;-4.30676;-22.93259;,
 0.04460;-4.26645;-22.93259;,
 8.15450;-14.16069;-24.84848;,
 -9.20029;-23.75609;-23.63857;,
 12.07021;-21.81407;-23.73608;,
 -3.52675;-111.55344;27.76637;,
 -1.75869;-85.82117;24.56137;,
 -11.20334;-134.15369;-26.10746;,
 -6.54272;-133.74595;30.75710;,
 -4.17016;-71.56941;22.45998;,
 -9.68138;-46.24893;24.73274;,
 -8.43327;-35.02091;23.08002;,
 -9.55379;-23.90745;-10.46388;,
 -8.46530;-13.22380;18.57030;,
 -4.00744;-1.16972;13.66012;,
 -12.21887;-35.35211;-15.40279;,
 -10.10665;-26.56536;-18.88252;,
 -12.91561;-46.41436;-32.59207;,
 -7.61021;-24.10526;-12.93357;,
 -8.24592;-13.20461;-10.99255;,
 21.78372;-162.83500;12.04686;,
 21.78372;-162.83500;-9.28791;,
 18.52390;-163.12021;-12.53045;,
 8.97180;-163.95590;-12.53045;,
 5.71198;-164.24110;-9.28786;,
 8.93000;-163.95957;15.33621;,
 18.56565;-163.11658;15.33621;;
 
 107;
 4;0,1,2,3;,
 3;4,5,6;,
 3;5,7,6;,
 3;7,8,6;,
 3;8,7,9;,
 3;2,1,7;,
 3;7,1,9;,
 3;9,1,10;,
 3;10,1,11;,
 3;11,12,10;,
 3;13,14,15;,
 3;15,14,16;,
 3;14,17,16;,
 3;16,17,18;,
 3;17,19,18;,
 3;19,20,18;,
 3;12,11,21;,
 3;21,11,22;,
 3;11,23,22;,
 3;24,25,26;,
 3;26,25,27;,
 3;25,28,27;,
 3;27,28,29;,
 3;28,30,29;,
 3;30,31,29;,
 4;32,33,34,35;,
 4;35,34,36,37;,
 4;38,39,40,41;,
 4;41,40,42,43;,
 4;25,24,44,45;,
 4;46,44,47,48;,
 4;26,27,49,50;,
 4;37,36,51,52;,
 4;43,42,53,54;,
 4;55,56,57,58;,
 4;59,60,61,62;,
 4;63,64,65,66;,
 4;66,67,68,69;,
 4;69,70,71,72;,
 4;73,74,75,76;,
 4;54,53,77,78;,
 4;52,51,79,80;,
 4;81,82,83,47;,
 4;84,81,72,85;,
 4;86,87,88,89;,
 4;90,91,92,93;,
 4;80,79,94,95;,
 4;95,94,96,97;,
 4;78,77,98,99;,
 4;97,96,30,100;,
 4;0,31,101,1;,
 4;89,88,102,103;,
 4;99,98,104,105;,
 4;103,102,106,9;,
 4;105,104,10,107;,
 4;34,41,43,36;,
 4;69,61,60,66;,
 4;40,58,73,42;,
 4;108,35,37,109;,
 4;34,33,38,41;,
 4;40,39,55,58;,
 4;66,60,110,63;,
 4;108,111,32,35;,
 4;81,90,93,72;,
 4;53,76,86,77;,
 4;51,54,78,79;,
 4;112,52,80,113;,
 4;47,4,90,81;,
 4;79,78,22,94;,
 4;113,80,95,114;,
 4;42,73,76,53;,
 4;72,93,61,69;,
 4;109,37,52,112;,
 4;36,43,54,51;,
 3;47,44,4;,
 3;44,50,4;,
 3;50,115,4;,
 3;22,23,94;,
 3;23,101,94;,
 3;101,96,94;,
 4;114,95,97,116;,
 4;44,24,26,50;,
 4;96,101,31,30;,
 4;116,97,100,117;,
 4;77,86,89,98;,
 3;88,106,102;,
 4;103,9,10,104;,
 3;105,107,99;,
 4;98,89,103,104;,
 3;118,119,120;,
 3;119,106,120;,
 3;106,88,120;,
 3;99,107,78;,
 3;107,21,78;,
 3;21,22,78;,
 4;121,115,50,122;,
 4;11,1,101,23;,
 4;8,9,106,119;,
 4;12,21,107,10;,
 4;38,33,123,124;,
 4;124,125,39,38;,
 4;55,39,125,126;,
 4;126,127,56,55;,
 4;63,110,13,15;,
 4;15,16,64,63;,
 4;32,111,128,129;,
 4;129,123,33,32;;
 
 MeshMaterialList {
  30;
  107;
  0,
  0,
  0,
  0,
  0,
  0,
  26,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  26,
  26,
  26,
  0,
  0,
  0,
  0,
  0,
  0,
  26,
  26,
  26,
  26,
  0,
  26,
  0,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  0,
  0,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  0,
  26,
  26,
  26,
  26,
  26,
  0,
  0,
  0,
  26,
  26,
  26,
  26,
  26,
  26,
  0,
  0,
  26,
  26,
  26,
  0,
  0,
  0,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26,
  26;;
  Material {
   0.400000;0.400000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.080000;0.080000;0.080000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.752000;0.160000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.080000;0.080000;0.080000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.048000;0.048000;0.048000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.632000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.336000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.048000;0.048000;0.048000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.048000;0.048000;0.048000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.048000;0.048000;0.048000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.048000;0.048000;0.048000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.048000;0.048000;0.048000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.632000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.632000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.632000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.632000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.336000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.336000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.336000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.336000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.048000;0.048000;0.048000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.780800;0.796800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.008000;0.008000;0.008000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.368000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  122;
  -0.997414;0.070091;-0.015893;,
  0.902107;0.423463;-0.082964;,
  0.245974;-0.954965;0.165950;,
  0.410698;-0.844332;0.344138;,
  0.878173;0.314186;0.360693;,
  0.365470;0.225059;0.903206;,
  0.213556;-0.918190;-0.333648;,
  0.296595;-0.930070;-0.216798;,
  0.870205;0.337784;-0.358671;,
  0.350059;0.283171;-0.892901;,
  -0.087158;0.996194;-0.000000;,
  -0.087162;0.996194;0.000000;,
  -0.918804;0.134018;0.371265;,
  -0.284219;0.280483;0.916815;,
  -0.087161;0.996194;-0.000000;,
  -0.314399;-0.084938;-0.945484;,
  -0.499331;0.865219;0.045438;,
  -0.907416;0.152274;-0.391673;,
  -0.904599;0.084815;-0.417739;,
  -0.351757;0.017776;-0.935922;,
  0.914335;0.158576;0.372618;,
  0.373491;0.170809;0.911773;,
  0.402662;-0.250082;-0.880524;,
  0.932082;-0.014375;-0.361963;,
  -0.069084;-0.984376;-0.161959;,
  -0.511420;-0.827145;-0.232984;,
  -0.401357;0.218948;-0.889367;,
  -0.917707;0.181785;-0.353227;,
  -0.140578;-0.964739;0.222523;,
  -0.058278;-0.935660;0.348058;,
  -0.918900;0.157280;0.361782;,
  -0.397672;0.158295;0.903770;,
  -0.927075;-0.002414;0.374868;,
  -0.395273;0.103435;0.912721;,
  -0.354056;-0.317838;-0.879559;,
  -0.914613;-0.178072;-0.363005;,
  0.394627;-0.357015;-0.846646;,
  0.921305;-0.162423;-0.353293;,
  0.382657;0.020533;0.923662;,
  0.924591;-0.003056;0.380948;,
  -0.922213;-0.043801;0.384194;,
  -0.380076;0.006944;0.924929;,
  -0.909501;-0.163797;0.382070;,
  -0.379268;-0.046334;0.924126;,
  -0.368326;-0.036874;-0.928965;,
  -0.966966;0.058059;-0.248204;,
  -0.321391;-0.421366;-0.848032;,
  -0.875811;-0.323352;-0.358328;,
  0.915805;0.117042;0.384190;,
  0.373094;0.072846;0.924929;,
  0.950395;0.205977;0.233074;,
  0.336147;0.240818;0.910501;,
  0.942704;0.223738;-0.247487;,
  0.370885;0.026520;-0.928300;,
  -0.914515;0.084088;0.395716;,
  -0.372775;0.178820;0.910528;,
  0.688717;0.407254;0.599845;,
  0.231359;0.325593;0.916767;,
  0.324373;-0.029057;-0.945483;,
  -0.087160;0.996194;0.000000;,
  0.892948;0.388869;-0.226769;,
  0.270203;0.226828;-0.935702;,
  0.914506;0.152181;-0.374858;,
  0.878289;0.256713;-0.403369;,
  -0.087159;0.996194;-0.000000;,
  -0.087154;0.996195;-0.000000;,
  -0.346246;0.330542;-0.877984;,
  -0.858461;0.307471;-0.410495;,
  0.279023;0.384644;-0.879884;,
  0.788563;0.452510;-0.416417;,
  -0.317867;0.467895;-0.824642;,
  -0.819777;0.400791;-0.409062;,
  0.732453;0.539538;-0.415224;,
  0.226149;0.515973;-0.826214;,
  -0.599441;0.783115;0.165536;,
  -0.400268;0.909496;-0.112263;,
  -0.926337;0.362275;0.103227;,
  -0.929128;0.369509;0.013562;,
  0.259188;0.958755;0.116661;,
  0.859089;0.505271;0.081654;,
  0.851180;0.516533;0.093201;,
  0.160974;0.970132;-0.181470;,
  0.927436;-0.033372;0.372491;,
  0.929422;0.015126;-0.368707;,
  0.287867;0.505245;-0.813547;,
  -0.380452;0.448238;-0.808913;,
  -0.970125;0.050397;-0.237314;,
  -0.908801;-0.193097;0.369856;,
  -0.357776;-0.200582;0.912011;,
  0.384092;-0.135906;0.913238;,
  -0.089685;0.732997;-0.674294;,
  -0.256036;0.926517;-0.275703;,
  -0.385125;0.121079;-0.914887;,
  -0.594603;0.803283;0.034410;,
  0.918070;0.329155;0.220917;,
  0.953775;0.157053;-0.256217;,
  -0.059892;0.976359;0.207691;,
  0.870361;0.399159;0.288347;,
  -0.087155;0.996195;-0.000000;,
  -0.087157;0.996195;-0.000000;,
  -0.206952;0.369660;0.905827;,
  -0.373667;0.340279;0.862892;,
  -0.877253;0.184059;-0.443338;,
  0.309177;0.400142;0.862726;,
  0.139761;0.400066;0.905767;,
  0.831969;0.333585;-0.443337;,
  -0.388303;0.237369;0.890436;,
  -0.703341;0.297276;0.645707;,
  0.644996;0.416155;0.640933;,
  0.345763;0.302235;0.888314;,
  0.096755;0.375288;-0.921844;,
  0.997201;0.074733;-0.002066;,
  -0.962890;0.269891;-0.000967;,
  0.901402;0.432982;-0.000966;,
  -0.010077;0.138835;0.990264;,
  0.944013;-0.329905;-0.001386;,
  0.353404;-0.534041;-0.768053;,
  -0.248671;-0.586692;-0.770685;,
  0.042942;-0.494084;-0.868353;,
  -0.514633;-0.618780;-0.593519;,
  -0.872815;-0.488049;0.001155;,
  0.038642;-0.438213;0.898040;;
  107;
  4;58,61,19,15;,
  3;0,17,77;,
  3;90,16,91;,
  3;16,74,77;,
  3;74,16,75;,
  3;19,61,92;,
  3;16,93,75;,
  3;75,61,81;,
  3;94,95,60;,
  3;96,78,81;,
  3;25,24,28;,
  3;28,24,29;,
  3;24,6,29;,
  3;29,6,2;,
  3;6,7,2;,
  3;7,3,2;,
  3;97,60,79;,
  3;79,60,1;,
  3;60,63,1;,
  3;11,10,14;,
  3;14,10,98;,
  3;10,65,98;,
  3;98,65,99;,
  3;65,64,99;,
  3;64,59,99;,
  4;89,82,4,5;,
  4;5,4,20,21;,
  4;83,84,9,8;,
  4;8,9,22,23;,
  4;100,101,12,13;,
  4;13,12,54,55;,
  4;102,15,19,18;,
  4;21,20,39,38;,
  4;23,22,36,37;,
  4;85,86,27,26;,
  4;26,27,35,34;,
  4;87,88,31,30;,
  4;30,31,33,32;,
  4;32,33,43,42;,
  4;34,35,47,46;,
  4;37,36,53,52;,
  4;38,39,48,49;,
  4;40,41,55,54;,
  4;41,40,42,43;,
  4;44,45,67,66;,
  4;45,44,46,47;,
  4;49,48,50,51;,
  4;51,50,56,57;,
  4;52,53,68,69;,
  4;57,56,103,104;,
  4;58,105,62,61;,
  4;66,67,71,70;,
  4;69,68,73,72;,
  4;106,107,76,106;,
  4;108,109,94,80;,
  4;4,8,23,20;,
  4;32,35,27,30;,
  4;9,26,34,22;,
  4;31,5,21,33;,
  4;4,82,83,8;,
  4;9,84,85,26;,
  4;30,27,86,87;,
  4;31,88,89,5;,
  4;40,45,47,42;,
  4;36,46,44,53;,
  4;39,37,52,48;,
  4;43,38,49,41;,
  4;54,0,45,40;,
  4;48,52,1,50;,
  4;41,49,51,55;,
  4;22,34,46,36;,
  4;42,47,35,32;,
  4;33,21,38,43;,
  4;20,23,37,39;,
  3;54,12,0;,
  3;12,18,0;,
  3;110,90,110;,
  3;1,63,50;,
  3;63,62,50;,
  3;62,111,50;,
  4;55,51,57,13;,
  4;12,112,102,18;,
  4;56,62,105,113;,
  4;13,57,104,100;,
  4;53,44,66,68;,
  3;67,76,71;,
  4;106,106,114,109;,
  3;72,80,69;,
  4;68,66,70,73;,
  3;0,77,45;,
  3;77,76,45;,
  3;76,67,45;,
  3;69,80,52;,
  3;80,79,52;,
  3;79,1,52;,
  4;92,17,18,19;,
  4;60,61,62,63;,
  4;74,75,76,77;,
  4;78,79,80,81;,
  4;83,82,115,115;,
  4;7,6,116,83;,
  4;117,116,6,118;,
  4;24,25,119,117;,
  4;87,86,25,120;,
  4;28,29,88,87;,
  4;89,88,29,121;,
  4;2,3,82,89;;
 }
 MeshTextureCoords {
  130;
  0.710360;0.250000;,
  0.673570;0.241360;,
  0.826430;0.241360;,
  0.789640;0.250000;,
  0.625000;0.524620;,
  0.752440;0.380220;,
  0.797500;0.316090;,
  0.875000;0.231880;,
  0.875000;0.228420;,
  0.832470;0.222400;,
  0.667310;0.222390;,
  0.625000;0.231940;,
  0.625000;0.228400;,
  0.595910;0.750000;,
  0.625000;0.800710;,
  0.404510;0.750000;,
  0.375000;0.800060;,
  0.625000;0.949290;,
  0.375000;0.949940;,
  0.595910;1.000000;,
  0.404510;1.000000;,
  0.625000;0.223310;,
  0.625000;0.225380;,
  0.625000;0.233520;,
  0.416520;0.500000;,
  0.375000;0.418970;,
  0.584510;0.500000;,
  0.625000;0.414640;,
  0.375000;0.331030;,
  0.625000;0.335360;,
  0.416520;0.250000;,
  0.584510;0.250000;,
  0.344650;0.051540;,
  0.395090;0.051490;,
  0.391100;0.073270;,
  0.352990;0.073350;,
  0.392810;0.124520;,
  0.340820;0.124250;,
  0.604840;0.051810;,
  0.655680;0.051490;,
  0.647200;0.073270;,
  0.608610;0.073740;,
  0.660430;0.124520;,
  0.606590;0.124520;,
  0.406660;0.508640;,
  0.375000;0.508070;,
  0.375000;0.508640;,
  0.395900;0.524620;,
  0.375000;0.521870;,
  0.625000;0.508040;,
  0.593450;0.508640;,
  0.390280;0.147390;,
  0.343770;0.147390;,
  0.656820;0.147390;,
  0.608600;0.147390;,
  0.844320;0.051550;,
  0.875000;0.050800;,
  0.875000;0.072290;,
  0.852800;0.073360;,
  0.625000;0.675700;,
  0.608930;0.676730;,
  0.606630;0.625480;,
  0.625000;0.625480;,
  0.395090;0.698240;,
  0.375000;0.714240;,
  0.375000;0.677930;,
  0.391100;0.676340;,
  0.375000;0.675800;,
  0.375000;0.625480;,
  0.392890;0.625480;,
  0.375210;0.625480;,
  0.375210;0.603020;,
  0.390280;0.602610;,
  0.839830;0.124520;,
  0.875000;0.124520;,
  0.875000;0.144820;,
  0.843140;0.147390;,
  0.649920;0.213390;,
  0.612380;0.213510;,
  0.388430;0.213390;,
  0.350130;0.213390;,
  0.388430;0.536610;,
  0.375000;0.535880;,
  0.375000;0.524620;,
  0.375000;0.537710;,
  0.375000;0.602610;,
  0.850080;0.213390;,
  0.875000;0.213490;,
  0.875000;0.217960;,
  0.836220;0.216510;,
  0.612380;0.536490;,
  0.625000;0.537660;,
  0.625000;0.602610;,
  0.609590;0.602610;,
  0.395900;0.225380;,
  0.346240;0.225380;,
  0.406660;0.241360;,
  0.328090;0.241360;,
  0.663820;0.216510;,
  0.625000;0.217920;,
  0.293970;0.250000;,
  0.593450;0.241360;,
  0.875000;0.219550;,
  0.758300;0.219380;,
  0.741760;0.219380;,
  0.625000;0.219550;,
  0.875000;0.220960;,
  0.625000;0.220930;,
  0.146880;0.073270;,
  0.159090;0.124240;,
  0.605060;0.698510;,
  0.155260;0.051490;,
  0.156230;0.147390;,
  0.149880;0.213390;,
  0.153760;0.225380;,
  0.625000;0.516470;,
  0.171980;0.241360;,
  0.206030;0.250000;,
  0.875000;0.225380;,
  0.875000;0.223330;,
  0.875000;0.215260;,
  0.625000;0.510170;,
  0.625000;0.508640;,
  0.404510;0.000000;,
  0.595910;0.000000;,
  0.675710;0.000000;,
  0.824290;-0.000000;,
  0.875000;0.000000;,
  0.175060;0.000000;,
  0.324940;0.000000;;
 }
}
