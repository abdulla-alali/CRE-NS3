/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2010 TELEMATICS LAB, DEE - Politecnico di Bari
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Giuseppe Piro  <g.piro@poliba.it>
 */



#ifndef MULTIPATH_V30_M8_H_
#define MULTIPATH_V30_M8_H_

static double multipath_M8_v_30[3000] = { 
 1.04482, 0.982109, 0.861595, 0.636734, 0.0246296, 0.351389, 0.722467, 0.890356, 0.978139, 1.01572, 1.01318, 0.972194, 0.887638, 0.742999, 0.486693, -0.232957, 0.220056, 0.538088, 0.666168, 0.710085, 0.692734, 0.613436, 0.447062, 0.0765056, -0.296194, 0.319524, 0.527253, 0.623775, 0.654991, 0.632462, 0.552359, 0.390086, 0.0415065, -0.486126, 0.217901, 0.434453, 0.532706, 0.562489, 0.535339, 0.445124, 0.258211, -0.197465, -0.224558, 0.237637, 0.419163, 0.502707, 0.523469, 0.488775, 0.389601, 0.185863, -0.352866, -0.165571, 0.232651, 0.399766, 0.476479, 0.492881, 0.454775, 0.352324, 0.144304, -0.409312, -0.196317, 0.19219, 0.353856, 0.424536, 0.43258, 0.380951, 0.252029, -0.0307029, -1.24992, 0.0247241, 0.291506, 0.422643, 0.484416, 0.495466, 0.45974, 0.371049, 0.206195, -0.121229, -1.0451, -0.0863822, 0.125371, 0.194441, 0.168724, 0.0290931, -0.406976, -0.318165, 0.160325, 0.378804, 0.50591, 0.578535, 0.609722, 0.603646, 0.558753, 0.466424, 0.302286, -0.0214681, -0.893836, 0.0513998, 0.289578, 0.402075, 0.449283, 0.449028, 0.406082, 0.317341, 0.169452, -0.0775576, -0.621528, -0.613438, -0.249892, -0.156263, -0.180086, -0.309061, -0.598841, -1.68104, -0.912981, -0.973858, -0.921271, -0.237625, 0.0999569, 0.325248, 0.487044, 0.60447, 0.686674, 0.738083, 0.760124, 0.751503, 0.707261, 0.615298, 0.443574, 0.0602464, -0.197465, 0.384873, 0.609643, 0.734183, 0.803371, 0.832065, 0.825007, 0.780897, 0.691378, 0.532706, 0.220266, -0.745729, 0.290361, 0.544745, 0.673559, 0.739724, 0.762336, 0.747675, 0.69517, 0.596909, 0.429608, 0.110003, -0.910743, 0.154009, 0.401522, 0.523148, 0.583032, 0.601118, 0.5849, 0.536005, 0.451263, 0.320278, 0.114429, -0.278605, -0.748165, -0.111683, 0.0910092, 0.190035, 0.236454, 0.24768, 0.230501, 0.185938, 0.109194, -0.0151753, -0.235398, -0.855357, -0.451024, -0.0510742, 0.161329, 0.303836, 0.406007, 0.479062, 0.527731, 0.553614, 0.556225, 0.533022, 0.478455, 0.380968, 0.212755, -0.125595, -0.762161, 0.0211622, 0.254433, 0.368104, 0.414991, 0.407759, 0.342091, 0.190451, -0.171736, -0.462898, 0.144362, 0.372582, 0.494347, 0.554558, 0.565944, 0.528261, 0.427957, 0.217008, -0.42194, 0.00117683, 0.370839, 0.54518, 0.637987, 0.676346, 0.666798, 0.60376, 0.462174, 0.139181, -0.381378, 0.365196, 0.618254, 0.758885, 0.840473, 0.880368, 0.884821, 0.854296, 0.783808, 0.658911, 0.437455, -0.102959, 0.0430813, 0.442059, 0.607878, 0.686736, 0.710903, 0.689909, 0.623001, 0.498774, 0.280916, -0.202015, -0.274696, 0.155218, 0.293398, 0.319012, 0.252552, 0.0540593, -0.662541, -0.0858982, 0.261996, 0.423715, 0.500066, 0.513543, 0.463293, 0.322972, -0.0351346, -0.283197, 0.316181, 0.550448, 0.67998, 0.749409, 0.77236, 0.750702, 0.676291, 0.520847, 0.166323, -0.192578, 0.448692, 0.683809, 0.812835, 0.883871, 0.91249, 0.903457, 0.85497, 0.757167, 0.581335, 0.213442, -0.215087, 0.431945, 0.648321, 0.754791, 0.799557, 0.796242, 0.745208, 0.633979, 0.418409, -0.166385, 0.120265, 0.503761, 0.677467, 0.770096, 0.812713, 0.81618, 0.78324, 0.710739, 0.587097, 0.379087, -0.0572925, -0.265155, 0.240919, 0.419751, 0.498997, 0.520186, 0.496151, 0.428951, 0.312224, 0.124998, -0.204839, -2.3369, -0.331162, -0.119408, -0.0580233, -0.07576, -0.15285, -0.278574, -0.427431, -0.520143, -0.453274, -0.264681, -0.0601832, 0.114889, 0.25283, 0.355638, 0.426303, 0.466712, 0.47708, 0.455407, 0.396169, 0.286583, 0.0932558, -0.322595, -0.561316, -0.0321929, 0.150043, 0.223431, 0.225637, 0.158918, -0.00444321, -0.410069, -0.560093, -0.0427762, 0.1481, 0.228043, 0.229562, 0.144058, -0.10399, -1.10596, 0.0508797, 0.351204, 0.52088, 0.625104, 0.683928, 0.704342, 0.68654, 0.623858, 0.496209, 0.235873, -1.10157, 0.217718, 0.520327, 0.677226, 0.766382, 0.810093, 0.815891, 0.784027, 0.707624, 0.565873, 0.287536, -1.63807, 0.280218, 0.56699, 0.714576, 0.797357, 0.837516, 0.843525, 0.817849, 0.75865, 0.658627, 0.498983, 0.221657, -0.650244, 0.0212674, 0.313417, 0.436598, 0.483468, 0.476843, 0.420604, 0.30503, 0.0924842, -0.414892, -0.350152, 0.0697601, 0.239264, 0.31981, 0.346518, 0.331158, 0.276567, 0.179404, 0.028102, -0.208375, -0.64785, -1.16151, -0.632808, -0.592463, -0.839735, -1.12456, -0.437637, -0.168528, -0.0153149, 0.0717178, 0.108312, 0.0975276, 0.0319787, -0.116031, -0.463427, -0.82617, -0.177279, 0.059935, 0.188512, 0.255632, 0.274626, 0.245365, 0.153781, -0.0515039, -0.751584, -0.178123, 0.197552, 0.396678, 0.524032, 0.607876, 0.659376, 0.683202, 0.68042, 0.648999, 0.582629, 0.466102, 0.256662, -0.271189, -0.0946308, 0.327117, 0.522688, 0.637716, 0.705949, 0.739767, 0.743853, 0.718606, 0.660455, 0.559594, 0.390955, 0.0667358, -0.820892, 0.141397, 0.386485, 0.507313, 0.564126, 0.573985, 0.539973, 0.454839, 0.292422, -0.0516751, -0.580423, 0.13892, 0.369854, 0.486361, 0.539804, 0.544577, 0.501364, 0.398034, 0.191674, -0.366124, -0.121251, 0.274069, 0.449614, 0.538672, 0.570555, 0.551281, 0.472124, 0.295976, -0.175564, -0.068629, 0.39004, 0.601246, 0.726363, 0.80132, 0.839159, 0.844724, 0.81817, 0.755017, 0.642812, 0.447169, 0.0173983, -0.131872, 0.378588, 0.578116, 0.682513, 0.732729, 0.742184, 0.714339, 0.645812, 0.523364, 0.306706, -0.213049, -0.106444, 0.310809, 0.488969, 0.582986, 0.627911, 0.636573, 0.613916, 0.560557, 0.473196, 0.34248, 0.144448, -0.203546, -1.30346, -0.226641, -0.00617977, 0.0885275, 0.123381, 0.120099, 0.0888097, 0.0351892, -0.0375969, -0.129206, -0.244964, -0.404978, -0.685103, -2.14441, -0.580679, -0.243402, -0.029111, 0.129448, 0.252093, 0.346741, 0.416855, 0.463655, 0.486741, 0.483966, 0.450506, 0.376156, 0.236529, -0.0508188, -1.11455, 0.0455098, 0.329638, 0.487864, 0.585758, 0.644006, 0.671082, 0.670313, 0.641857, 0.582831, 0.485739, 0.332835, 0.0721497, -0.643282, -0.198789, 0.126126, 0.265187, 0.327338, 0.340211, 0.313249, 0.248304, 0.141618, -0.0183156, -0.261418, -0.697678, -1.30709, -0.729282, -0.66801, -0.807604, -1.34301, -1.14699, -0.83307, -0.859243, -1.88233, -0.610144, -0.197026, 0.055102, 0.232079, 0.360987, 0.453933, 0.51708, 0.553492, 0.564152, 0.548148, 0.502181, 0.418851, 0.281438, 0.0429904, -0.566136, -0.291744, 0.0691625, 0.218956, 0.283257, 0.289617, 0.242581, 0.130782, -0.0916214, -0.72085, -0.363296, -0.00578761, 0.147875, 0.215106, 0.2215, 0.168997, 0.0390629, -0.247701, -1.3193, -0.172847, 0.0893742, 0.216463, 0.270722, 0.266193, 0.196564, 0.0234707, -0.479319, -0.267493, 0.171295, 0.3824, 0.510242, 0.58869, 0.630216, 0.639388, 0.616083, 0.555292, 0.443185, 0.240288, -0.248852, -0.181174, 0.262907, 0.456464, 0.563619, 0.619841, 0.637036, 0.617997, 0.558815, 0.445377, 0.234498, -0.313162, -0.0948368, 0.312009, 0.498901, 0.604284, 0.660252, 0.677511, 0.657916, 0.596056, 0.473977, 0.232539, -0.660324, 0.142167, 0.476297, 0.651605, 0.758933, 0.823765, 0.855941, 0.858978, 0.832399, 0.771461, 0.66382, 0.4762, 0.0676381, -0.135255, 0.409725, 0.623519, 0.74111, 0.805423, 0.830777, 0.821692, 0.776781, 0.687718, 0.531093, 0.22437, -0.824532, 0.286572, 0.548602, 0.684286, 0.758328, 0.79074, 0.789065, 0.755129, 0.686429, 0.574697, 0.399106, 0.0940954, -1.05377, -0.0735562, 0.168532, 0.244513, 0.226471, 0.11213, -0.182733, -0.879081, -0.0186239, 0.231728, 0.355525, 0.408594, 0.40456, 0.339244, 0.1837, -0.199865, -0.390689, 0.16791, 0.387865, 0.505651, 0.563509, 0.573884, 0.53714, 0.441811, 0.248245, -0.255767, -0.117299, 0.312104, 0.50244, 0.605826, 0.656181, 0.664778, 0.633807, 0.558383, 0.422159, 0.173856, -0.533348, -0.0848866, 0.238631, 0.369273, 0.412567, 0.38918, 0.292238, 0.0729314, -0.657229, -0.0942412, 0.245914, 0.402534, 0.476881, 0.492645, 0.452277, 0.340373, 0.0937559, -1.06568, 0.061152, 0.368315, 0.523047, 0.606113, 0.639858, 0.630899, 0.577211, 0.466174, 0.25781, -0.255398, -0.15367, 0.260754, 0.428679, 0.503552, 0.516071, 0.470164, 0.349523, 0.0831267, -1.8948, 0.115014, 0.401886, 0.549385, 0.629288, 0.662656, 0.656476, 0.610463, 0.51679, 0.352098, 0.0327288, -0.978748, 0.0728601, 0.312676, 0.422876, 0.466176, 0.460458, 0.409639, 0.308182, 0.135316, -0.182709, -2.13619, -0.255151, -0.0254322, 0.0622614, 0.0807982, 0.055938, 0.00723976, -0.0379876, -0.0420854, 0.0207986, 0.138111, 0.275561, 0.40686, 0.51935, 0.608222, 0.671659, 0.708277, 0.715613, 0.688513, 0.615747, 0.469112, 0.143244, -0.366791, 0.375041, 0.629829, 0.772863, 0.856796, 0.898358, 0.902926, 0.869375, 0.789167, 0.637572, 0.324051, -0.455097, 0.450276, 0.705577, 0.839736, 0.911931, 0.940281, 0.930485, 0.881281, 0.783459, 0.610071, 0.257973, -0.308633, 0.416298, 0.637069, 0.741549, 0.781386, 0.770341, 0.707453, 0.575935, 0.312944, -0.79167, 0.231704, 0.523768, 0.659831, 0.721254, 0.728633, 0.684493, 0.576596, 0.357879, -0.284349, 0.121276, 0.484966, 0.653505, 0.742419, 0.780381, 0.776784, 0.732361, 0.63987, 0.476611, 0.161514, -0.966753, 0.181203, 0.421592, 0.527834, 0.562964, 0.542206, 0.462598, 0.298468, -0.0652646, -0.455875, 0.178811, 0.397336, 0.507264, 0.556968, 0.561639, 0.525107, 0.443524, 0.301803, 0.0523708, -0.598663, -0.274988, 0.0584092, 0.186391, 0.226661, 0.204036, 0.118579, -0.054073, -0.427682, -0.839438, -0.215602, -0.0135381, 0.0780958, 0.108643, 0.0951446, 0.0457848, -0.0326713, -0.128495, -0.216155, -0.253301, -0.20898, -0.100554, 0.0295637, 0.151922, 0.25399, 0.331864, 0.384662, 0.411978, 0.412661, 0.383827, 0.319169, 0.204559, 0.00188484, -0.468503, -0.469382, -0.00780173, 0.188494, 0.29862, 0.361415, 0.392026, 0.398034, 0.383828, 0.352128, 0.304444, 0.240847, 0.158879, 0.0506483, -0.105817, -0.386657, -1.92625, -0.302027, 0.0253736, 0.229056, 0.377655, 0.491535, 0.57876, 0.642717, 0.684423, 0.703196, 0.696522, 0.659048, 0.579599, 0.431169, 0.117585, -0.548453, 0.294873, 0.559378, 0.708041, 0.797862, 0.847021, 0.862216, 0.844512, 0.790147, 0.687849, 0.506966, 0.124311, -0.219103, 0.382914, 0.594803, 0.700485, 0.745418, 0.742267, 0.690527, 0.576014, 0.34821, -0.351232, 0.14819, 0.4973, 0.661994, 0.74931, 0.786437, 0.782102, 0.736396, 0.640907, 0.469509, 0.122051, -0.487556, 0.263198, 0.484239, 0.586662, 0.623127, 0.607334, 0.537597, 0.394657, 0.103137, -1.30811, 0.121755, 0.383786, 0.509079, 0.565891, 0.573713, 0.53771, 0.454402, 0.308566, 0.0519414, -0.61425, -0.295765, 0.0137017, 0.106808, 0.0894609, -0.0441148, -0.444174, -0.496142, 0.0143821, 0.226189, 0.338202, 0.389695, 0.392855, 0.348829, 0.248863, 0.0640108, -0.324179, -0.730478, -0.136095, 0.0363917, 0.0824734, 0.0351041, -0.132465, -0.645181, -0.440157, -0.0314197, 0.137619, 0.204296, 0.190089, 0.0754974, -0.270313, -0.451495, 0.141589, 0.386475, 0.526751, 0.605703, 0.636376, 0.619743, 0.54538, 0.376852, -0.0683457, -0.0246537, 0.455005, 0.669936, 0.794565, 0.865803, 0.896181, 0.889048, 0.841345, 0.740946, 0.551879, 0.106195, 0.0593119, 0.542196, 0.742296, 0.85008, 0.904101, 0.917345, 0.893508, 0.830235, 0.717419, 0.526747, 0.149356, -0.366747, 0.293509, 0.483724, 0.553454, 0.547742, 0.469391, 0.286141, -0.193828, -0.127007, 0.3084, 0.483755, 0.561322, 0.572266, 0.518939, 0.378984, 0.0467153, -0.423792, 0.27598, 0.507953, 0.622433, 0.668111, 0.655829, 0.577835, 0.394087, -0.134164, 0.103604, 0.520771, 0.714325, 0.822241, 0.876322, 0.886603, 0.853424, 0.767676, 0.599897, 0.226997, -0.101011, 0.505199, 0.722849, 0.833428, 0.882248, 0.881816, 0.831154, 0.714566, 0.474664, -0.401212, 0.364857, 0.688837, 0.848081, 0.933973, 0.971033, 0.967044, 0.921434, 0.824735, 0.647618, 0.269529, -0.0910916, 0.519736, 0.7322, 0.837899, 0.883454, 0.882758, 0.83762, 0.739757, 0.560803, 0.183429, -0.210671, 0.409017, 0.615867, 0.713173, 0.747755, 0.73247, 0.666512, 0.534524, 0.280871, -0.556772, 0.109151, 0.416749, 0.551622, 0.607378, 0.606401, 0.550947, 0.426334, 0.173824, -0.783466, 0.0664527, 0.372278, 0.517194, 0.588875, 0.611025, 0.590809, 0.526572, 0.406015, 0.18929, -0.334579, -0.219412, 0.194862, 0.373315, 0.470556, 0.52333, 0.547193, 0.551145, 0.541797, 0.524819, 0.505222, 0.48688, 0.471651, 0.458638, 0.444041, 0.421459, 0.381867, 0.311832, 0.186105, -0.0683184, -1.61931, -0.0383299, 0.278776, 0.454492, 0.564287, 0.630105, 0.659826, 0.654852, 0.611186, 0.516252, 0.334052, -0.101316, -0.150943, 0.344565, 0.555177, 0.674286, 0.741108, 0.769327, 0.763757, 0.724144, 0.645061, 0.511712, 0.281479, -0.270823, -0.125358, 0.261891, 0.416333, 0.482019, 0.489602, 0.44562, 0.342245, 0.145925, -0.307272, -0.38363, 0.0863237, 0.26611, 0.34944, 0.37446, 0.352846, 0.285731, 0.165384, -0.0321869, -0.390963, -1.52761, -0.490117, -0.354193, -0.418784, -0.788689, -0.778147, -0.265482, -0.0492966, 0.0591395, 0.0944129, 0.0585161, -0.0773744, -0.473683, -0.501651, 0.0210874, 0.251881, 0.386588, 0.464572, 0.498903, 0.492682, 0.441591, 0.329536, 0.104308, -0.608401, -0.0726015, 0.279506, 0.450994, 0.546905, 0.5946, 0.603659, 0.575989, 0.507314, 0.383443, 0.161537, -0.393058, -0.202853, 0.192396, 0.36495, 0.45617, 0.499845, 0.509245, 0.490835, 0.448358, 0.384728, 0.303572, 0.211167, 0.118882, 0.0442455, 0.00569282, 0.00998831, 0.0459398, 0.0936953, 0.136218, 0.162477, 0.165504, 0.139575, 0.0773975, -0.0342657, -0.227286, -0.62576, -0.9895, -0.413346, -0.234137, -0.169902, -0.178318, -0.252329, -0.404212, -0.681297, -1.33727, -1.29211, -1.29004, -1.21814, -0.554093, -0.238234, -0.0413263, 0.08323, 0.150395, 0.160969, 0.100118, -0.0912716, -1.01737, -0.0673482, 0.297736, 0.504695, 0.641025, 0.731842, 0.786969, 0.809893, 0.799946, 0.751777, 0.651238, 0.458217, -0.02779, 0.0675119, 0.513735, 0.712322, 0.823518, 0.882041, 0.899158, 0.876666, 0.808567, 0.675039, 0.408369, -0.944031, 0.377635, 0.67255, 0.821103, 0.900796, 0.933332, 0.925236, 0.874761, 0.770263, 0.575434, 0.116599, 0.0923884, 0.560184, 0.752358, 0.852327, 0.897369, 0.899242, 0.859502, 0.771059, 0.610504, 0.291554, -0.611484, 0.363078, 0.605689, 0.721645, 0.77166, 0.772917, 0.72847, 0.630808, 0.452783, 0.083725, -0.383436, 0.271196, 0.477409, 0.570028, 0.597675, 0.573357, 0.495945, 0.349392, 0.0766759, -0.796378, -0.145628, 0.115835, 0.182961, 0.1239, -0.132291, -0.720546, 0.128974, 0.413516, 0.576897, 0.676501, 0.731015, 0.747249, 0.725716, 0.660731, 0.535163, 0.294928, -0.461815, 0.112342, 0.445804, 0.602056, 0.68203, 0.711574, 0.698469, 0.641379, 0.528584, 0.322733, -0.160096, -0.149561, 0.292103, 0.468792, 0.553459, 0.581892, 0.56498, 0.5032, 0.387448, 0.18891, -0.207578, -0.666024, -0.0657744, 0.0916685, 0.114392, 0.0237439, -0.271413, -0.715006, 0.0149956, 0.275588, 0.421589, 0.505419, 0.544128, 0.543264, 0.501516, 0.409325, 0.237983, -0.12854, -0.527243, 0.112264, 0.334425, 0.449966, 0.507912, 0.524423, 0.505148, 0.450014, 0.353213, 0.198292, -0.0647961, -0.762595, -0.367197, -0.0439044, 0.0898516, 0.14826, 0.162178, 0.145718, 0.108483, 0.0598301, 0.0105705, -0.0279293, -0.0478363, -0.0496947, -0.0431674, -0.0434212, -0.0686392, -0.144443, -0.330427, -1.04225, -0.388781, 0.00293349, 0.220468, 0.364388, 0.461956, 0.523729, 0.553695, 0.551832, 0.514018, 0.429126, 0.267642, -0.0856474, -0.48878, 0.171458, 0.406238, 0.532627, 0.59889, 0.619198, 0.595181, 0.517644, 0.354513, -0.0398773, -0.183276, 0.365198, 0.59551, 0.731159, 0.814775, 0.861462, 0.877284, 0.863718, 0.818499, 0.734169, 0.591882, 0.333386, -0.527196, 0.183596, 0.502489, 0.657785, 0.743106, 0.78402, 0.789843, 0.762958, 0.700598, 0.592754, 0.411808, 0.0521172, -0.479714, 0.227164, 0.454264, 0.57237, 0.634358, 0.657708, 0.64923, 0.610649, 0.5398, 0.429433, 0.261691, -0.0159849, -0.755193, -0.325593, -0.0306173, 0.0694305, 0.0751604, -0.00345605, -0.210718, -0.965174, -0.32862, 0.0214923, 0.195804, 0.293412, 0.340022, 0.343154, 0.300539, 0.197441, -0.0162193, -0.686474, -0.195906, 0.174558, 0.360397, 0.471206, 0.535381, 0.563272, 0.557906, 0.517222, 0.432567, 0.280402, -0.0214737, -1.08993, 0.0436564, 0.308462, 0.445236, 0.518484, 0.547358, 0.537734, 0.488086, 0.388215, 0.207619, -0.180632, -0.486701, 0.0980969, 0.309264, 0.416969, 0.466602, 0.472432, 0.437836, 0.358753, 0.220315, -0.0227269, -0.625885, -0.409488, -0.0689549, 0.0402852, 0.0374136, -0.0812522, -0.464343, -0.50423, 0.0267477, 0.259694, 0.395429, 0.474284, 0.510033, 0.506738, 0.462017, 0.364964, 0.183725, -0.216189, -0.470316, 0.0809688, 0.275936, 0.361644, 0.376512, 0.322506, 0.1693, -0.254643, -0.240913, 0.255902, 0.477166, 0.60593, 0.68017, 0.712652, 0.706577, 0.658203, 0.553307, 0.347634, -0.212504, 0.0527141, 0.454393, 0.64208, 0.748508, 0.805177, 0.822883, 0.803988, 0.744322, 0.629426, 0.414896, -0.153555, 0.106993, 0.503465, 0.687915, 0.793332, 0.851953, 0.875884, 0.869867, 0.834534, 0.766755, 0.657606, 0.484364, 0.170641, -1.36647, 0.151586, 0.408244, 0.533311, 0.597096, 0.621467, 0.615568, 0.583396, 0.526057, 0.442248, 0.32756, 0.171657, -0.0516766, -0.438407, -1.15482, -0.38484, -0.174953, -0.0704041, -0.0124101, 0.0192497, 0.0332475, 0.0327788, 0.0174096, -0.0165198, -0.0767348, -0.178697, -0.360272, -0.784002, -0.854347, -0.340471, -0.119164, 0.00912558, 0.0833273, 0.116074, 0.110404, 0.0627572, -0.0397561, -0.234699, -0.699149, -0.718917, -0.267016, -0.0970911, -0.03428, -0.0546702, -0.182961, -0.601469, -0.504567, -0.00367009, 0.237537, 0.389873, 0.491054, 0.555252, 0.58854, 0.592906, 0.567221, 0.50658, 0.399039, 0.213441, -0.174479, -0.514231, 0.0805355, 0.288405, 0.39013, 0.430586, 0.421673, 0.361233, 0.230278, -0.0440798, -1.83644, -0.0140423, 0.271369, 0.420009, 0.503144, 0.541921, 0.543704, 0.509023, 0.431928, 0.294459, 0.0389202, -0.819993, -0.10943, 0.208441, 0.361566, 0.443536, 0.479732, 0.479041, 0.442922, 0.36646, 0.233823, -0.00463243, -0.677125, -0.245658, 0.112222, 0.28521, 0.387061, 0.448019, 0.480624, 0.49118, 0.483125, 0.458256, 0.417173, 0.359279, 0.28236, 0.181388, 0.0452501, -0.154242, -0.52377, -1.0407, -0.329598, -0.0804553, 0.071211, 0.178444, 0.259472, 0.322447, 0.371441, 0.408502, 0.434506, 0.449517, 0.452904, 0.443273, 0.418186, 0.373494, 0.301733, 0.187733, -0.00761405, -0.465425, -0.445056, 0.0385326, 0.260918, 0.399565, 0.491964, 0.551583, 0.583726, 0.589523, 0.566715, 0.50845, 0.398197, 0.188319, -0.404998, -0.0546793, 0.342793, 0.540922, 0.663109, 0.740047, 0.783265, 0.797194, 0.782281, 0.735332, 0.647624, 0.497564, 0.215632, -1.21957, 0.166753, 0.448131, 0.583245, 0.647485, 0.66028, 0.623984, 0.527095, 0.326547, -0.233203, 0.041554, 0.442792, 0.62995, 0.734675, 0.78802, 0.800147, 0.772223, 0.697466, 0.554135, 0.265419, -1.13066, 0.297798, 0.568882, 0.704727, 0.773198, 0.793296, 0.769237, 0.695206, 0.548658, 0.24487, -0.682923, 0.335147, 0.592919, 0.723768, 0.789534, 0.808196, 0.784059, 0.712358, 0.574215, 0.304184, -0.899952, 0.235422, 0.522811, 0.658012, 0.720112, 0.729466, 0.68898, 0.587883, 0.385307, -0.149848, 0.0457365, 0.453952, 0.635245, 0.731398, 0.774815, 0.775977, 0.736004, 0.647646, 0.487405, 0.16856, -0.715856, 0.248179, 0.494395, 0.61671, 0.676805, 0.694095, 0.676025, 0.624652, 0.538291, 0.411084, 0.230058, -0.0352386, -0.486199, -1.36878, -0.751263, -0.976922, -0.945117, -0.399386, -0.18039, -0.0905087, -0.105079, -0.268902, -1.18714, -0.218361, 0.148041, 0.351509, 0.479518, 0.556778, 0.591854, 0.585373, 0.530085, 0.402811, 0.118229, -0.773321, 0.253807, 0.533966, 0.689743, 0.783844, 0.836104, 0.854249, 0.840473, 0.792863, 0.704206, 0.556123, 0.29259, -0.514303, 0.0839498, 0.390818, 0.522147, 0.57481, 0.572087, 0.517579, 0.40049, 0.17926, -0.383538, -0.192331, 0.185412, 0.334484, 0.391728, 0.385255, 0.317441, 0.169402, -0.140301, -1.15947, -0.104143, 0.122277, 0.205913, 0.201074, 0.103998, -0.159876, -1.15339, -0.0395843, 0.23523, 0.375165, 0.44308, 0.455412, 0.411893, 0.294861, 0.0345124, -1.94601, 0.0483118, 0.335689, 0.47698, 0.544149, 0.555041, 0.509118, 0.386466, 0.104448, -0.829662, 0.225137, 0.499378, 0.645253, 0.725397, 0.758267, 0.748746, 0.693085, 0.574989, 0.340119, -0.430487, 0.180946, 0.517091, 0.678489, 0.764261, 0.800137, 0.794151, 0.745663, 0.644845, 0.461235, 0.0672397, -0.24094, 0.331648, 0.529047, 0.617943, 0.640581, 0.605001, 0.499505, 0.270179, -0.548767, 0.148915, 0.481105, 0.643146, 0.729733, 0.765696, 0.758329, 0.70555, 0.593633, 0.377246, -0.216637, 0.0913697, 0.471798, 0.645043, 0.736891, 0.777328, 0.775786, 0.732263, 0.637165, 0.459391, 0.0632324, -0.163295, 0.397979, 0.617503, 0.740619, 0.812218, 0.84844, 0.856378, 0.838992, 0.796562, 0.7267, 0.622952, 0.469972, 0.224225, -0.351292, -0.166805, 0.220239, 0.391949, 0.489025, 0.545358, 0.574142, 0.581259, 0.56888, 0.536484, 0.480627, 0.393198, 0.255575, 0.0135825, -0.711306, -0.172432, 0.182375, 0.362104, 0.471055, 0.536504, 0.568493, 0.570318, 0.541073, 0.475315, 0.359297, 0.155449, -0.309821, -0.346444, 0.115346, 0.299127, 0.388468, 0.419228, 0.400462, 0.327943, 0.1789, -0.136985, -0.900506, -0.0175239, 0.225684, 0.344101, 0.395104, 0.394169, 0.341749, 0.224012, -0.00937938, -0.713663, -0.233182, 0.100348, 0.243218, 0.300648, 0.295565, 0.227549, 0.0726412, -0.277128, -0.750735, -0.0810328, 0.122391, 0.198015, 0.183739, 0.0604125, -0.334341, -0.324613, 0.195078, 0.43102, 0.57218, 0.657645, 0.700948, 0.706257, 0.671605, 0.587145, 0.424352, 0.070322, -0.358354, 0.306534, 0.534539, 0.651936, 0.707446, 0.715101, 0.676003, 0.579604, 0.389215, -0.0784932, -0.0541722, 0.402263, 0.593671, 0.693394, 0.737499, 0.73725, 0.69373, 0.599067, 0.427896, 0.0844091, -0.611747, 0.183226, 0.393384, 0.473854, 0.473211, 0.390428, 0.171917, -0.773637, 0.128199, 0.458462, 0.627582, 0.722849, 0.768171, 0.771026, 0.730277, 0.634877, 0.449675, 0.00897856, -0.0456158, 0.441281, 0.642197, 0.749955, 0.803339, 0.815269, 0.789108, 0.721579, 0.599925, 0.385915, -0.108367, -0.0871745, 0.345819, 0.519356, 0.603738, 0.635637, 0.628197, 0.586515, 0.511761, 0.402593, 0.256006, 0.0694307, -0.150343, -0.356546, -0.43389, -0.343556, -0.201915, -0.0925403, -0.0434335, -0.0752853, -0.249992, -1.30679, -0.168149, 0.194249, 0.400277, 0.532952, 0.616313, 0.659136, 0.663046, 0.623449, 0.525285, 0.322166, -0.263886, 0.0682948, 0.458126, 0.640852, 0.740332, 0.785435, 0.783847, 0.731919, 0.610275, 0.347348, -3.37803, 0.37861, 0.673702, 0.828926, 0.916998, 0.959097, 0.962204, 0.925992, 0.842541, 0.688209, 0.377795, -0.563607, 0.453678, 0.704989, 0.828591, 0.88597, 0.894343, 0.856497, 0.764084, 0.58693, 0.19328, -0.0688479, 0.495044, 0.701232, 0.803812, 0.846399, 0.841864, 0.791131, 0.684351, 0.488485, 0.0544046, -0.113474, 0.381378, 0.554554, 0.620414, 0.613158, 0.530307, 0.326809, -0.346533, 0.15414, 0.516318, 0.690161, 0.783847, 0.82445, 0.819843, 0.767855, 0.65377, 0.427611, -0.253665, 0.213547, 0.565546, 0.729374, 0.814466, 0.848167, 0.838864, 0.785733, 0.677969, 0.481257, 0.0378516, -0.0747741, 0.409942, 0.593582, 0.679057, 0.704641, 0.680621, 0.60451, 0.458307, 0.176561, -1.05955, 0.0767253, 0.339193, 0.44205, 0.459209, 0.399959, 0.234915, -0.221998, -0.155173, 0.304572, 0.502931, 0.607552, 0.6533, 0.649641, 0.593431, 0.46462, 0.185935, -1.0515, 0.254599, 0.534565, 0.682343, 0.765568, 0.804814, 0.807523, 0.774767, 0.701994, 0.575262, 0.353665, -0.173904, -0.0671591, 0.340421, 0.508142, 0.5889, 0.61615, 0.600148, 0.540925, 0.428199, 0.227889, -0.219936, -0.314284, 0.172542, 0.369099, 0.476531, 0.53621, 0.564036, 0.567828, 0.5519, 0.518573, 0.468569, 0.400707, 0.310697, 0.187874, 0.00445812, -0.342922, -0.901355, -0.141779, 0.120194, 0.276943, 0.381122, 0.449147, 0.486607, 0.49379, 0.466379, 0.392684, 0.241552, -0.112745, -0.399207, 0.228415, 0.479055, 0.628916, 0.72484, 0.78292, 0.809571, 0.806482, 0.771662, 0.698239, 0.569082, 0.333484, -0.339257, 0.0953972, 0.449381, 0.614767, 0.703605, 0.744184, 0.746239, 0.711662, 0.636155, 0.50572, 0.278931, -0.260044, -0.144253, 0.250911, 0.407051, 0.473358, 0.481323, 0.438122, 0.337294, 0.150302, -0.246649, -0.59329, -0.0229342, 0.155273, 0.215716, 0.195212, 0.0850396, -0.196357, -1.00243, -0.0455448, 0.222697, 0.364746, 0.441264, 0.470661, 0.45825, 0.401257, 0.285878, 0.0675748, -0.515679, -0.23891, 0.145694, 0.3208, 0.417013, 0.466956, 0.483894, 0.474679, 0.443686, 0.394601, 0.331663, 0.260754, 0.190096, 0.129517, 0.0871097, 0.0644121, 0.0542916, 0.0434862, 0.0159551, -0.0479478, -0.182459, -0.500441, -0.941278, -0.220503, 0.040511, 0.188398, 0.273149, 0.309274, 0.298352, 0.230675, 0.0720332, -0.340914, -0.380588, 0.1336, 0.358971, 0.491118, 0.569575, 0.608099, 0.611416, 0.578952, 0.504443, 0.370696, 0.125325, -0.592542, -0.108038, 0.221732, 0.364448, 0.425043, 0.427401, 0.373673, 0.247724, -0.0164452, -1.38948, -0.050071, 0.237618, 0.376602, 0.444132, 0.461761, 0.435829, 0.36446, 0.236354, 0.0183551, -0.428513, -0.715375, -0.241154, -0.143242, -0.214362, -0.571319, -0.600856, -0.0654068, 0.162624, 0.283468, 0.333759, 0.318379, 0.217704, -0.0637698, -0.629605, 0.190998, 0.47153, 0.634447, 0.735259, 0.791613, 0.809309, 0.787379, 0.717083, 0.572447, 0.25474, -0.346529, 0.449481, 0.705994, 0.847203, 0.928296, 0.96666, 0.967974, 0.931366, 0.848691, 0.696301, 0.389518, -0.566776, 0.470735, 0.729354, 0.861873, 0.93098, 0.955511, 0.94134, 0.887156, 0.783461, 0.602334, 0.234848, -0.262971, 0.407949, 0.615156, 0.706812, 0.730932, 0.697618, 0.597755, 0.386659, -0.232057, 0.140779, 0.512737, 0.68433, 0.774595, 0.812441, 0.806745, 0.756804, 0.651561, 0.455269, -0.00306164, -0.0432817, 0.423307, 0.609749, 0.701931, 0.736741, 0.72464, 0.664189, 0.54032, 0.299811, -0.465809, 0.121358, 0.453475, 0.610439, 0.693049, 0.728105, 0.725237, 0.686816, 0.6098, 0.483503, 0.278359, -0.122301, -0.558303, 0.0440026, 0.224602, 0.293051, 0.295434, 0.242566, 0.128915, -0.075201, -0.506574, -0.76301, -0.255123, -0.0950886, -0.0437214, -0.0604377, -0.135451, -0.271864, -0.483339, -0.790222, -1.12963, -1.05332, -0.678976, -0.374888, -0.159701, -0.0113836, 0.0839831, 0.132384, 0.132807, 0.0742832, -0.0798814, -0.514645, -0.446155, 0.0434203, 0.271218, 0.409703, 0.496114, 0.543802, 0.557576, 0.537225, 0.477231, 0.362137, 0.145811, -0.443337, -0.13561, 0.252902, 0.436339, 0.541805, 0.600669, 0.624727, 0.618507, 0.58235, 0.512539, 0.398656, 0.212994, -0.149879, -0.68418, 0.0241287, 0.25532, 0.381846, 0.458229, 0.504172, 0.52953, 0.54031, 0.540646, 0.533528, 0.520987, 0.50405, 0.482606, 0.455257, 0.419141, 0.369564, 0.298978, 0.193976, 0.0248457, -0.312064, -0.883028, -0.116, 0.139138, 0.284, 0.372393, 0.421464, 0.437249, 0.420084, 0.364948, 0.257465, 0.0557278, -0.461293, -0.294311, 0.133539, 0.331613, 0.447909, 0.516642, 0.550481, 0.554422, 0.529311, 0.472362, 0.375498, 0.218726, -0.0603134, -1.06199, -0.19972, 0.0882743, 0.216975, 0.271146, 0.271202, 0.218085, 0.0946797, -0.168285, -2.08066, -0.149741, 0.148528, 0.306915, 0.399716, 0.448751, 0.461679, 0.439271, 0.375937, 0.254639, 0.0216458, -0.718223, -0.144338, 0.205069, 0.37938, 0.480818, 0.536211, 0.554937, 0.538838, 0.48372, 0.375878, 0.174806, -0.32709, -0.210633, 0.22343, 0.416147, 0.522646, 0.576742, 0.588994, 0.560059, 0.481384, 0.3253, -0.0195383, -0.452073, 0.230487, 0.471868, 0.604788, 0.679211, 0.710809, 0.703809, 0.655003, 0.550778, 0.34882, -0.182069, 0.0165677, 0.432728, 0.623238, 0.730154, 0.785934, 0.801189, 0.777365, 0.708017, 0.572101, 0.295682, -1.50864, 0.327492, 0.61689, 0.771423, 0.86273, 0.912632, 0.929737, 0.91698, 0.873514, 0.794232, 0.66621, 0.454543, 0.00672748, -0.14982, 0.340159, 0.521119, 0.60584, 0.634466, 0.61951, 0.562995, 0.458702, 0.286114, -0.0248271, -1.63645, -0.132387, 0.103569, 0.187239, 0.189653, 0.123785, -0.0231247, -0.315053, -1.56277, -0.473977, -0.273132, -0.287251, -0.576228, -0.685312, -0.067861, 0.20735, 0.37817, 0.490046, 0.559425, 0.593025, 0.592429, 0.554736, 0.470271, 0.312798, -0.0147002, -0.666337, 0.141122, 0.385502, 0.512376, 0.577421, 0.597492, 0.576998, 0.512323, 0.388345, 0.156517, -0.495157, -0.103735, 0.250691, 0.409484, 0.48784, 0.513446, 0.493856, 0.425901, 0.292062, 0.0301706, -1.02186, -0.0576828, 0.242717, 0.38843, 0.463761, 0.492155, 0.481414, 0.431693, 0.335603, 0.170646, -0.142985, -1.33225, -0.125993, 0.123204, 0.241638, 0.295362, 0.303857, 0.273003, 0.200884, 0.0758769, -0.138351, -0.617581, -0.64445, -0.191197, -0.00575388, 0.0943524, 0.14867, 0.172814, 0.17479, 0.159429, 0.130006, 0.0889239, 0.038053, -0.0210578, -0.0869067, -0.157504, -0.229326, -0.295603, -0.3446, -0.360632, -0.331437, -0.257968, -0.154412, -0.0383169, 0.0769903, 0.183582, 0.277276, 0.355908, 0.418183, 0.46297, 0.488813, 0.493424, 0.47288, 0.419942, 0.31951, 0.131825, -0.332993, -0.272432, 0.197688, 0.412906, 0.542544, 0.623157, 0.667777, 0.681108, 0.663093, 0.608868, 0.505044, 0.313807, -0.145056, -0.129377, 0.345386, 0.556112, 0.680706, 0.757157, 0.799438, 0.813413, 0.800898, 0.760638, 0.687596, 0.569566, 0.374365, -0.0304661, -0.3014, 0.263855, 0.476498, 0.592574, 0.657417, 0.686817, 0.68716, 0.66024, 0.604302, 0.512966, 0.370358, 0.130655, -0.468507, -0.206027, 0.169579, 0.337942, 0.428818, 0.473324, 0.482321, 0.458609, 0.399221, 0.293132, 0.109077, -0.282592, -0.565184, 0.016294, 0.235565, 0.355418, 0.421016, 0.447143, 0.438359, 0.393099, 0.302614, 0.142385, -0.175302, -1.05044, -0.0895625, 0.157714, 0.278971, 0.333605, 0.337221, 0.289735, 0.175401, -0.06512, -1.01029, -0.143849, 0.177789, 0.339803, 0.430002, 0.472561, 0.475727, 0.440371, 0.360914, 0.220747, -0.0302795, -0.709073, -0.340442, -0.0280013, 0.0713271, 0.0554101, -0.0976446, -0.723703, -0.195899, 0.202569, 0.411321, 0.540896, 0.620362, 0.660477, 0.664421, 0.62995, 0.547517, 0.390289, 0.0567279, -0.517432, 0.239772, 0.479895, 0.604385, 0.666506, 0.681973, 0.653734, 0.575182, 0.422718, 0.107443, -0.708665, 0.211237, 0.456408, 0.575919, 0.62833, 0.629528, 0.580474, 0.468623, 0.248958, -0.352173, -0.0536343, 0.310676, 0.460745, 0.518482, 0.506347, 0.415771, 0.186452, -0.96593, 0.184113, 0.503762, 0.67055, 0.765211, 0.81003, 0.811314, 0.766095, 0.658802, 0.436795, -0.289773, 0.280524, 0.633996, 0.809641, 0.910423, 0.963362, 0.977909, 0.955865, 0.892803, 0.774204, 0.556154, -0.00732551, 0.22146, 0.613839, 0.787938, 0.879323, 0.919552, 0.918986, 0.87904, 0.793492, 0.642263, 0.356807, -1.09182, 0.298302, 0.574074, 0.704772, 0.767168, 0.783183, 0.760092, 0.697943, 0.589788, 0.415312, 0.107553, -1.16909, -0.035883, 0.205137, 0.288629, 0.289298, 0.219696, 0.0627025, -0.273722, -0.957986, -0.166804, 0.0450115, 0.131047, 0.146377, 0.106605, 0.0151058, -0.129414, -0.321621, -0.504967, -0.512087, -0.305925, -0.0579918, 0.151848, 0.314819, 0.4361, 0.520911, 0.572299, 0.590807, 0.573867, 0.513754, 0.390802, 0.142622, -0.848145, 0.0667533, 0.381388, 0.537998, 0.622097, 0.656676, 0.648328, 0.594632, 0.481781, 0.265068, -0.317278, -0.044148, 0.33604, 0.502298, 0.583419, 0.608731, 0.585706, 0.510002, 0.360394, 0.0570894, -1.09762, 0.0858198, 0.32939, 0.433688, 0.459603, 0.416355, 0.283241, -0.0505895, -0.437999, 0.230367, 0.470856, 0.600337, 0.667529, 0.686999, 0.660782, 0.580333, 0.41549, 0.0344731, -0.212635, 0.365481, 0.588079, 0.709542, 0.774649, 0.798317, 0.785386, 0.734735, 0.638463, 0.474379, 0.166623, -1.43247, 0.141923, 0.390607, 0.50036, 0.539597, 0.526421, 0.462999, 0.338731, 0.11578 
 };


 #endif /* MULTIPATH_V30_M8_H_ */
 
