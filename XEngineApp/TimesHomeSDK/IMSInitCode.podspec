#
# Be sure to run `pod lib lint CLAAccount.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'IMSInitCode'
  s.version          = '1.0.0'
  s.summary          = 'A short description of IMSInitCode.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
DESC

  s.homepage         = 'http://gitlab.alibaba-inc.com/iot-aep-ios/IMSInitCode'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'Copyright', :text => 'Alibaba-inc copyright' }
  s.author           = { 'app-generate' => 'app-generate@alibaba-inc.com' }
  s.source           = { :git => 'http://gitlab.alibaba-inc.com/iot-aep-ios/IMSInitCode.git', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'
  s.source_files = ['IMSInitCode/*.{h,m}']
  s.public_header_files = 'IMSInitCode/*.h'
  s.frameworks = 'UIKit', 'Foundation'

  s.dependency 'IMSLaunchKit'
  s.dependency 'IMSApiClient'
  s.dependency 'IMSBoneKit'
  s.dependency 'MJRefresh'
  s.dependency 'AKReactNative'
  s.dependency 'ZipArchive'
  s.dependency 'IMSMobileChannel'
  s.dependency 'IMSDeviceGateway'
  s.dependency 'IMSBreezeSDK'
  s.dependency 'IMSOtaBusinessSdk'
  s.dependency 'IMSReactNativeExtension'
  s.dependency 'IMSAuthentication'
  s.dependency 'AlicloudALBBOpenAccount'
  s.dependency 'IMSThingCapability'
  s.dependency 'IMSDeviceCenter'
  s.dependency 'Reachability'
  s.dependency 'CocoaAsyncSocket'
  s.dependency 'AlicloudPushIoT'
end
