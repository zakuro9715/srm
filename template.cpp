#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;

${<if Problem.Description.Modulo}
  static const int MOD = ${Problem.Description.Modulo};
${<end}

class ${ClassName}
{
public:
  ${Method.ReturnType} ${Method.Name}(${foreach Method.Params p, }${p.Type} ${p.Name}${end})
  {
    return ${Method.ReturnType;zeroval};
  }
}

${CutBegin}
${<TestCode}
${CutEnd}
