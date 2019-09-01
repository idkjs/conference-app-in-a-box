open ReactNative;
open ReactNavigation;
open AppStyle.Schedule;

module Schedule = {
  type talk = TalkType.t;
  type state = {
    .
    "talks": TalkType.talks,
    "currentDate": string,
    "loading": bool,
  };
  let day1 = "November 10";
  let day2 = "November 11";

  [@react.component]
  let make = (~navigation: Navigation.t) => {
    let (currentDate, setCurrentDate) = React.useState(() => day1);
    let toggleDate = date => {
      setCurrentDate(date);
    };
    <Queries.ListTalksQuery>
      ...{({result}) =>
        switch (result) {
        | Error(error) =>
          Js.Console.error(error);
          <Text> {ReasonReact.string("Error")} </Text>;
        | Loading =>
          <View style=styles##loading>
            <ActivityIndicator
              size=ActivityIndicator.Size.large
              color="white"
            />
          </View>
        | Data(data) =>
          let talkData =
            [%get_in data##listTalks#??items]
            ->Belt.Option.getWithDefault([||])
            ->Belt.Array.keepMap(item => item);

          // Js.log2("LIST_TALKS_TALKDATA: ", talkData);

          let filteredTalks =
            talkData->Belt.Array.keep(talk => {
              let talkDate = Belt.Option.getWithDefault(talk##date, "");
              talkDate === currentDate;
            });
          // Js.log2("filteredTalks: ", filteredTalks);

          <View style=styles##container>
            <ScrollView>
              <View style=styles##listContainer>
                <FlatList
                  data=filteredTalks
                  keyExtractor={(talk, _) => talk##id}
                  renderItem={props =>
                    <ScheduleItem
                      // let talk = props##item;
                      onPress={_ =>
                        navigation->Navigation.navigateWithParams(
                          "Talk",
                          {"talk": props##item},
                        )
                      }
                      talk=props##item
                    />
                  }
                />
              </View>
            </ScrollView>
            // <BaseHeader />
            // BaseHeader is what it causing the extra header space in schedule
            <View style=styles##tabBottomContainer>
              <TouchableHighlight
                underlayColor=Colors.primaryDark
                onPress={_ => toggleDate(_ => day1)}>
                <View style=styles##bottomButton>
                  <Text style=styles##bottomButtonText>
                    {day1 |> React.string}
                  </Text>
                </View>
              </TouchableHighlight>
              <TouchableHighlight
                underlayColor=Colors.primaryDark
                onPress={_ => toggleDate(_ => day2)}>
                <View style=styles##bottomButton>
                  <Text style=styles##bottomButtonText>
                    {day2 |> React.string}
                  </Text>
                </View>
              </TouchableHighlight>
            </View>
          </View>;
        }
      }
    </Queries.ListTalksQuery>;
  };
  make->NavigationOptions.(
          setNavigationOptions(
            t(
              ~headerLeft=
                <Image
                  source=Theme.logo
                  resizeMode=`contain
                  style=styles##logo
                />,
              (),
            ),
          )
        );
};
let defaultNavigationOptions = {
  "headerStyle":
    Style.(
      style(
        // ~backgroundColor="red",
        ~backgroundColor=Colors.primary,
        // ~borderBottomColor="red",
        ~borderBottomColor=Colors.primaryLight,
        ~borderBottomWidth=1.,
        (),
      )
    ),
};
let configOptions = StackUtils.config(~defaultNavigationOptions, ());
// let headerStyle = Style.(
//       style(
//         ~backgroundColor="red",
//         // ~backgroundColor=Colors.primary,
//         // ~borderBottomColor="red",
//         ~borderBottomColor=Colors.primaryLight,
//         ~borderBottomWidth=1.,
//         (),
//       )
//     );
// let configOptions = StackNavigator.config(~headerStyle, ());
// let routes = {
//   "Schedule": {
//     screen: Schedule.make,
//   },
//   "Talk": {
//     screen: Pager.make,
//   },
// };
let make =
  StackNavigator.(
    makeWithConfig(
      {
        "Schedule": {
          screen: Schedule.make,
        },
        "Talk": {
          screen: Pager.make,
        },
      },
      configOptions,
    )
  );

make->NavigationOptions.setNavigationOptions(
  NavigationOptions.t(
    ~title="Schedule",
    ~tabBarIcon=Helpers.tabBarIcon(~name=`calendar),
    (),
  ),
) /* ))*/;
// headerStyle only being applied when passed to defaultNavigationOptions.
// this version doesnt shared headerStyle values
// let make =
//   StackNavigator.
//     make(
//       {
//         "Schedule": {
//           screen: Schedule.make,
//         },
//         "Talk": {
//           screen: Pager.make,
//         },
//       }
//   );
// make->NavigationOptions.setNavigationOptions(
// NavigationOptions.t(
//   ~title="Schedule",
//   ~tabBarIcon=Helpers.tabBarIcon(~name=`calendar),
//   ~headerStyle=headerStyle,
//   (),