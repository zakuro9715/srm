#include<bits/stdc++.h>
#define INF (1 << 30)

using namespace std;
typedef long long ll;

${<if Problem.Description.Modulo}
static const int MOD = ${Problem.Description.Modulo};
${<end}

struct ${ClassName}
{
  ${Method.ReturnType} ${Method.Name}(${Method.Params})
  {
    return ${Method.ReturnType;zeroval};
  }
};

${CutBegin}
${<TestCode}
${CutEnd}
