open ReactNative;
open Expo;

let styles =
  Style.(
    StyleSheet.create({
      "container":
        style(
          ~flex=1.,
          ~justifyContent=`center,
          ~alignItems=`center,
          ~backgroundColor="#F5FCFF",
          (),
        ),
      "instructions": style(~textAlign=`center, ~color="#ffffff", ()),
    })
  );

[@react.component]
let make = () => {
  Js.log("Auth Callback");
  <ReasonApollo.Consumer>
    {client =>
       <Queries.ListTalksQuery>
         {data =>
            <View style=styles##container>
              <LinearGradient
                colors=[|"#DD4B39", "#C62C19"|]
                start=[|0.0, 0.0|]
                _end=[|1.0, 1.0|]
                style=Style.(style(~padding=dp(12.), ~borderRadius=12., ()))>
                <TouchableOpacity onPress={_ => Js.log2("Log data", data)}>
                  <Text style=styles##instructions>
                    {"Log data" |> React.string}
                  </Text>
                </TouchableOpacity>
              </LinearGradient>
            </View>}
       </Queries.ListTalksQuery>}
  </ReasonApollo.Consumer>;
};