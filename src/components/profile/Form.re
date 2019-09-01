open ReactNative;
open ProfileStyle;

[@react.component]
let make = (~onChange: ('a, 'a) => unit, ~twitter, ~github) =>
  <View>
    <View>
      <TextInput
        onChangeText={value => onChange("twitter", value)}
        style=styles##input
        value=twitter
        autoCapitalize=`none
        autoCorrect=false
      />
    </View>
    <View>
      <TextInput
        onChangeText={value => onChange("github", value)}
        style=styles##input
        value=github
        autoCapitalize=`none
        autoCorrect=false
      />
    </View>
  </View>;

// [@genType]
// let default = make;