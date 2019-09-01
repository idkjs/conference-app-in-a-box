open ReactNative;
open ProfileStyle;

[@react.component]
let make = (~github, ~twitter) =>
  <View>
    <View style=styles##iconContainer>
      <Icon color=Colors.highlight name="logo-twitter" size=29 />
      <Text style=styles##twitterHandle> {twitter |> React.string} </Text>
    </View>
    <View style=styles##iconContainer>
      <Icon color="white" name="logo-github" size=29 />
      <Text style=styles##twitterHandle> {github |> React.string} </Text>
    </View>
  </View>;